#define _DEFAULT_SOURCE // for usleep
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>
#include <fcntl.h>

typedef struct node {
    char **paragraph;
    int paragraphLength;
    unsigned int speed;
    struct node *nextNode0;
    struct node *nextNode1;
    char *question;
} node;

struct termios canonical;
struct termios nonCanonical;
int currentFreeArrayIndex = 0;
int freeArraySize = 4; // this value should be at least 4 for smartMalloc to work correctly.
void **nodeFreeArray;

void *smartMalloc(size_t size) {
	void *mallocedPointer = malloc(size);
    memset(mallocedPointer, 0, size);
    if (currentFreeArrayIndex >= (int)(freeArraySize / 2)) {
        freeArraySize *= 2;
        nodeFreeArray = (void **)realloc(nodeFreeArray, sizeof(void *) * (unsigned long)freeArraySize);
    }
	nodeFreeArray[currentFreeArrayIndex++] = mallocedPointer;
	return mallocedPointer;
}

void *smartRealloc(void *oldMallocedPointer, size_t size) {
	void *newMallocedPointer = realloc(oldMallocedPointer, size);
	for (int i=0; i<freeArraySize; i++) {
		if (nodeFreeArray[i] == oldMallocedPointer) {
			nodeFreeArray[i] = newMallocedPointer;
		}
	}
	return newMallocedPointer;
}

void freeFromArray(void **arrayToFree) {
	for (int i=0; i<currentFreeArrayIndex; i++) {
		free(arrayToFree[i]);
	}
	free(arrayToFree);
}

node *makeNode(char **paragraph, int paragraphLength, unsigned int speed, node *nextNode0, node *nextNode1, char question[]) {
    node *newNode = (node *)smartMalloc(sizeof(node));
    newNode -> paragraph = (char **)smartMalloc(sizeof(char *) * (unsigned long)paragraphLength);
    for (int i=0;i<paragraphLength;i++)
    {
        newNode -> paragraph[i] = paragraph[i];
    }
    newNode -> speed = speed;
    newNode -> nextNode0 = nextNode0;
    newNode -> nextNode1 = nextNode1;
    newNode -> question = question;
    newNode -> paragraphLength = paragraphLength;
    return newNode;
}

void setUpCanonicalStructs() {
    tcgetattr(0, &canonical);
    tcgetattr(0, &nonCanonical);
    nonCanonical.c_lflag &= (tcflag_t)(~ICANON & ~ECHO);
}

void revertToCanonical() {
    tcsetattr(0, TCSANOW, &canonical);
}

void makeNonCanonical() {
    tcsetattr(0, TCSANOW, &nonCanonical);
}

void makeNonCanonicalUntilExit() {
    tcsetattr(0, TCSANOW, &nonCanonical);
    atexit(&revertToCanonical);
}

void disableBlocking() {
    fcntl(0, F_SETFL, O_NONBLOCK);
}

void enableBlocking() {
    int blockingFlags = fcntl(0, F_GETFL);
    blockingFlags &= ~O_NONBLOCK;
    fcntl(0, F_SETFL, blockingFlags);
}

void clearInputBuffer() { // for use in non-canonical mode
    while (getc(stdin) != EOF){}
}

void waitForInput(int character) {
    while (1)
    {
        char mychar = (char)getc(stdin);
        if (mychar == character) // if ascii newline
        {
            break;
        }
    }
}

void sleepms(unsigned int milliseconds) {
    usleep(milliseconds * 1000);
}

void printEllipse()
{
    for (int i=0;i<3;i++)
    {
        sleepms(360);
        printf(".");
        fflush(stdout);
    }
}

void forceBlockingScanf(const char *formatter, char *address) {
    enableBlocking();
    revertToCanonical();
    scanf(formatter, address);
    disableBlocking();
    makeNonCanonical();
}

void typeOutSentence(char sentence[], unsigned int speed) {
    int continue_count = 0;
    for (int i=0;i<(int)strlen(sentence);i++)
    {
        if (sentence[i] == '{' && sentence[i+1] == '.' && sentence[i+2] == '.' && sentence[i+3] == '.' && sentence[i+4] == '}')
        {
            printEllipse();
            continue_count = 5;
        }
        if (continue_count)
        {
            continue_count -= 1;
            continue;
        }
        sleepms(speed);
        if (getc(stdin) == ' ')
        {
            char *restOfString = sentence + (sizeof(char) * (unsigned long)i);
            printf("%s", restOfString);
            break;
        }
        printf("%c", sentence[i]);
        fflush(stdout);
    }
    waitForInput(10);
}

int askBool(char sentence[], unsigned int speed) {
    system("clear");
    char input;
    int returnval;
    for (int i=0;i<(int)strlen(sentence);i++)
    {
        sleepms(speed);
        if (getc(stdin) == ' ')
        {
            char *restOfString = sentence + (sizeof(char) * (unsigned long)i);
            printf("%s", restOfString);
            break;
        }
        printf("%c", sentence[i]);
        fflush(stdout);
    }
    forceBlockingScanf("%c", &input);
    clearInputBuffer();
    fflush(stdin);
    if (input == 'y')
    {
        returnval = 1;
    }
    else
    {
        returnval = 0;
    }
    return returnval;
}

void typeOutParagraph(char *paragraph[], int size, unsigned int speed) { // speaker is first element in paragraph array.
    char *speaker = (char *)smartMalloc((strlen(paragraph[0]) + 2) * sizeof(char)); 
    strcpy(speaker, paragraph[0]);
    strcat(speaker, ":");
    system("clear");
    for (int i=1;i<size;i++)
    {
        if (strcmp(speaker, ":"))
        {
            printf("%s\n", speaker);
        }
        typeOutSentence(paragraph[i], speed);
        system("clear");
    }
}

void typeOutNode(node *nodeArg) {
    typeOutParagraph(nodeArg -> paragraph, nodeArg -> paragraphLength, nodeArg -> speed);

}

void startFromNode(node *nodeArg) {
    node *currentNode = nodeArg;
    typeOutNode(currentNode);
    while (currentNode -> nextNode0 || currentNode -> nextNode1)
    {
        if (currentNode -> question)
        {
            int outcome = askBool(currentNode -> question, currentNode -> speed);
            if (outcome)
            {
                currentNode = currentNode -> nextNode1;
            }
            else
            {
                currentNode = currentNode -> nextNode0;
            }
        }
        else
        {
            currentNode = currentNode -> nextNode0;
        }
        typeOutNode(currentNode);
    }

}

int pointerInArray(node *ptrArg, node **ptrArray, int pointerArrayLength) {
    for (int i=0; i<pointerArrayLength; i++) {
        if (ptrArray[i] == ptrArg) {
            return 1;
        }
    }
    return 0;
}

char *getMainCharacter() {
    char *mc = (char *)smartMalloc(sizeof(char)*201);
    while (1)
    {
        system("clear");
        printf("Please enter your name: ");
        scanf("%100s", mc);
        if (strcmp(mc, "Jason") && strcmp(mc, "Andy"))
        {
            break;
        }
        else
        {
            printf("Invalid name. Please try again.");
            system("clear");
        }
    }
    return mc;
}

int main() {
    nodeFreeArray = (void **)malloc(sizeof(void *) * (unsigned long)freeArraySize);
    char *mc = getMainCharacter();
    disableBlocking();
    clearInputBuffer();
    system("clear");
    setUpCanonicalStructs();
    makeNonCanonicalUntilExit();
    char *introParagraph[2] = {"", "You walk into the food court and see Andy and Jason sitting together, talking about music."};
    node *introNode0 = makeNode(introParagraph, 2, 30, NULL, NULL, "Join them [y/n]?: ");
    char *paragraph1[2] = {"Jason", "Hey Andy, what's your favorite MCR song?"};
    node *introNode1 = makeNode(paragraph1, 2, 30, NULL, NULL, NULL);
    introNode0 -> nextNode1 = introNode1;
    char *paragraph2[2] = {"Andy", "Cemetery Drive, no doubt."};
    node *andyGenericNode1 = makeNode(paragraph2, 2, 30, NULL, NULL, NULL);
    introNode1 -> nextNode0 = andyGenericNode1;
    char *endParagraph0[5] = {"", "Why didn't you sit with them?", "What the hell is wrong with you?", "Stop being a dick.", "Ending 1/6: ~{You're An Asshole}~"};
    node *ending0 = makeNode(endParagraph0, 5, 30, NULL, NULL, NULL);
    introNode0 -> nextNode0 = ending0;
    char *paragraph3[2] = {"Jason", "Bro what? That song sucks ass! How can you even listen to that?"};
    node *andyGenericNode2 = makeNode(paragraph3, 2, 30, NULL, NULL, NULL);
    andyGenericNode1 -> nextNode0 = andyGenericNode2;
    char *paragraph4[3] = {"Andy", "HOW DARE YOU INSULT MY FAVORITE SONG!", "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"};
    node *andyGenericNode3 = makeNode(paragraph4, 3, 30, NULL, NULL, "Stick up for Andy [y/n]?: ");
    andyGenericNode2 -> nextNode0 = andyGenericNode3;
    char *paragraph5[2] = {mc, "Hey, I actually like that song."};
    node *andyPositiveNode1 = makeNode(paragraph5, 2, 30, NULL, NULL, NULL);
    andyGenericNode3 -> nextNode1 = andyPositiveNode1;
    char *paragraph6[2] = {mc, "Gotta agree with Jason. Song sucks."};
    node *andyNegativeNode1 = makeNode(paragraph6, 2, 30, NULL, NULL, NULL);
    andyGenericNode3 -> nextNode0 = andyNegativeNode1;
    char *paragraph7[3] = {"Jason", "At least you have someone to share your terrible music taste with, Andy.", "I didn't think someone like that existed."};
    node *andyPositiveNode2 = makeNode(paragraph7, 3, 30, NULL, NULL, NULL);
    andyPositiveNode1 -> nextNode0 = andyPositiveNode2;
    char *paragraph8[2] = {"Jason", "I'm glad someone shares my cultured opinion."};
    node *andyNegativeNode2 = makeNode(paragraph8, 2, 30, NULL, NULL, NULL);
    andyNegativeNode1 -> nextNode0 = andyNegativeNode2;
    char *paragraph9[3] = {"Jason", "Anyhow, today's going to be busy. I should probably head to the desk now.", "I'll see you guys around."};
    node *andyGenericNode4 = makeNode(paragraph9, 3, 30, NULL, NULL, NULL);
    andyNegativeNode2 -> nextNode0 = andyGenericNode4;
    andyPositiveNode2 -> nextNode0 = andyGenericNode4;
    char *paragraph10[2] = {"", "After Jason gets up and leaves, you notice he forgot one of his notebooks and left it on the table."};
    node *andyGenericNode5 = makeNode(paragraph10, 2, 30, NULL, NULL, "Read the notebook [y/n]?: ");
    andyGenericNode4 -> nextNode0 = andyGenericNode5;
    // start of don't read node.
    char *paragraph11[6] = {"", "You open the notebook and read what appears to be complete gibberish.", "The words \"k talbloc nemlec nac\" are marked on the page in dark yellow ink.",
    "Upon flipping to the second page, you notice it has a familiar yet unpleasant scent, but you can't quite place it...", "The other pages are filled with random bits of architecture and statistics notes that are of no interest to you.", 
    "In the half hour or so you spent fiddling through Jason's personal business instead of eating lunch, your class starts."};
    node *readJasonNode1 = makeNode(paragraph11, 6, 30, NULL, NULL, NULL);
    andyGenericNode5 -> nextNode1 = readJasonNode1;
    char *paragraph12[2] = {mc, "Shit, I'm late for class! Gotta go!"};
    node *readJasonNode2 = makeNode(paragraph12, 2, 30, NULL, NULL, NULL);
    readJasonNode1 -> nextNode0 = readJasonNode2;
    char *paragraph13[2] = {"", "You run to class as fast as you possibly can to soften the blow of being late."};
    node *readJasonNode3 = makeNode(paragraph13, 2, 30, NULL, NULL, NULL);
    readJasonNode2 -> nextNode0 = readJasonNode3;
    char *paragraph14[2] = {mc, "Did I make it in time? I wonder what the teacher is on about..."};
    node *readJasonNode4 = makeNode(paragraph14, 2, 30, NULL, NULL, NULL);
    readJasonNode3 -> nextNode0 = readJasonNode4;
    char *paragraph16[4] = {"", "You sit down and notice the classroom is less crowded than usual.", "Seems like some people chose not to come to class today.", "The emptiness of the classroom is unsettling."};
    node *readJasonNode5 = makeNode(paragraph16, 4, 30, NULL, NULL, NULL);
    readJasonNode4 -> nextNode0 = readJasonNode5;
    // branch aside from read jason node. the don't read branch starts here.
    char *paragraph17[2] = {"", "You leave Jason's notebook on the lunch table. Something about it makes you feel uneasy."};
    node *dontReadJasonNode1 = makeNode(paragraph17, 2, 30, NULL, NULL, NULL);
    andyGenericNode5 -> nextNode0 = dontReadJasonNode1;
    char *paragraph18[2] = {"Andy", "Oh, Jason left his notebook, huh?"};
    node *dontReadJasonNode2 = makeNode(paragraph18, 2, 30, NULL, NULL, NULL);
    dontReadJasonNode1 -> nextNode0 = dontReadJasonNode2;
    char *paragraph19[2] = {mc, "Yeah. There's something I don't like about it."};
    node *dontReadJasonNode3 = makeNode(paragraph19, 2, 30, NULL, NULL,NULL);
    dontReadJasonNode2 -> nextNode0 = dontReadJasonNode3;
    char *paragraph20[2] = {"Andy", "Interesting. I'll take your word for it."};
    node *dontReadJasonNode4 = makeNode(paragraph20, 2, 30, NULL, NULL, NULL);
    dontReadJasonNode3 -> nextNode0 = dontReadJasonNode4;
    char *paragraph21[6] = {"", "You sit and eat your lunch (whatever that might be because I have no idea) with Andy.", "You feel nourished and ready for the challenges ahead.",
    "As you finish your lunch, you see that it is time for class, so you head over a little early to get a headstart.", 
    "You take out your textbook and plop it on the table. It makes a loud thump.", "As you finish setting up your desk and getting everything sorted, class starts..."};
    node *dontReadJasonNode5 = makeNode(paragraph21, 6, 30, NULL, NULL, NULL);
    dontReadJasonNode4 -> nextNode0 = dontReadJasonNode5;
    // collapse into classroom talk.
    char *paragraph81[3] = {"John D. Professor", "Listen up, kids!", "Today's not going to be a super eventful day. Just turn to page 250 in your textbooks."};
    node *intermediateNode1 = makeNode(paragraph81, 3, 30, NULL, NULL, NULL);
    readJasonNode5 -> nextNode0 = intermediateNode1;
    dontReadJasonNode5 -> nextNode0 = intermediateNode1;
    char *paragraph82[6] = {"", "You turn to page 250 in your textbook.", "\"Chapter 15, Section 2: The Gentle Art of Octeeel Grift\"", "The words on the page don't make sense to you.", "\"Jake neentjeneisdotrrtkc. Hanson trod fleecloco octeeel grift. Lit@tmr detox my@ceins.\"", "Gibberish fills the entire page, which ends with \"babe removal\"."};
    node *intermediateNode2 = makeNode(paragraph82, 6, 30, NULL, NULL, NULL);
    intermediateNode1 -> nextNode0 = intermediateNode2;
    char *paragraph83[2] = {"Nhu", "This is stupid. I'm taking a nap."};
    node *intermediateNode3 = makeNode(paragraph83, 2, 30, NULL, NULL, NULL);
    intermediateNode2 -> nextNode0 = intermediateNode3;
    char *paragraph84[4] = {"", "You have no idea who Nhu is or what she is doing in this classroom, but she fell asleep faster than you could look over to her while she was talking.", "Her friends seem unfazed, though, and you notice one of them drawing suspicious fan art of some character named \"Joker\" while agressively mumbling about an orange scented hand soap.", "There are a couple other people in the room, but you firstly overhear orange hand soap girl asking what \"maybe\" means."};
    node *intermediateNode4 = makeNode(paragraph84, 4, 30, NULL, NULL, NULL);
    intermediateNode3 -> nextNode0 = intermediateNode4;
    char *paragraph85[2] = {"Aariba", "Ah yes, I see.. mhm... mhm.."};
    node *intermediateNode5 = makeNode(paragraph85, 2, 30, NULL, NULL, NULL);
    intermediateNode4 -> nextNode0 = intermediateNode5;
    char *paragraph86[3] = {"Brain", "...", "(My receptacle isn't at full power... I must lay low.)"};
    node *intermediateNode6 = makeNode(paragraph86, 3, 30, NULL, NULL, NULL);
    intermediateNode5 -> nextNode0 = intermediateNode6;
    char *paragraph87[3] = {"", "Apparently you can read thoughts. Who knew?", "After your mind reading session, your class ends. It's time to push forward."};
    node *intermediateNode7 = makeNode(paragraph87, 3, 30, NULL, NULL, "Head home [y/n]?: ");
    intermediateNode6 -> nextNode0 = intermediateNode7;
    // (dont) go home
    char *paragraph88[5] = {"", "You decide to head home.", "Your house is enveloped in a very distinct smell.", "The odor in your abode manifests into something physical, although you can't make out what.", "It crawls up your body and consumes you as you utter your final words..."};
    node *homeNode1 = makeNode(paragraph88, 5, 30, NULL, NULL, NULL);
    intermediateNode7 -> nextNode1 = homeNode1;
    char *paragraph89[2] = {mc, "Is that... a piss monster...?"};
    node *homeNode2 = makeNode(paragraph89, 2, 30, NULL, NULL, NULL);
    homeNode1 -> nextNode0 = homeNode2;
    char *paragraph90[3] = {"", "You got pissed on. What a way to go out." ,"Ending 2/6: ~{Golden Shower}~"};
    node *homeNodeEnd = makeNode(paragraph90, 3, 30, NULL, NULL, NULL);
    homeNode2 -> nextNode0 = homeNodeEnd;
    // don't go home
    char *paragraph91[5] = {"", "You decide not to head home and loiter around school for a while.", "As you walk around, you notice a highly decorated door with what looks like a marble handle.",
    "It's surprising you haven't noticed this before...", "As you step closer, you feel a warm and welcoming presence behind the door."};
    node *noHomeNode1 = makeNode(paragraph91, 5, 30, NULL, NULL, "Open the door [y/n]?: ");
    intermediateNode7 -> nextNode0 = noHomeNode1;
    // open the door ending
    char *paragraph92[2] = {"", "You open the door..."};
    node *openDoorNode1 = makeNode(paragraph92, 2, 30, NULL, NULL, NULL);
    noHomeNode1 -> nextNode1 = openDoorNode1;
    char *paragraph93[2] = {"The Elder God, Ryab", "I've been expecting you."};
    node *openDoorNode2 = makeNode(paragraph93, 2, 30, NULL, NULL, NULL);
    openDoorNode1 -> nextNode0 = openDoorNode2;
    char *paragraph94[4] = {"", "You feel an overwhelming presence from this man. It's nothing like you've ever experienced before.", "Yet, somehow, you feel comfortable and safe.", "You are at a loss for words."};
    node *openDoorNode3 = makeNode(paragraph94, 4, 30, NULL, NULL, NULL);
    openDoorNode2 -> nextNode0 = openDoorNode3;
    char *paragraph95[3] = {"The Elder God's Chosen, Angy", "The Elder God has summoned you for a reason.", "Do not disappoint him."};
    node *openDoorNode4 = makeNode(paragraph95, 3, 30, NULL, NULL, NULL);
    openDoorNode3 -> nextNode0 = openDoorNode4;
    char *paragraph96[2] ={mc, "And what might that reason be?"};
    node *openDoorNode5 = makeNode(paragraph96, 2, 30, NULL, NULL, NULL);
    openDoorNode4 -> nextNode0 = openDoorNode5;
    char *paragraph97[3] = {"The Elder God, Ryab", "There are ancient evils inhabiting this establishment, like few you've ever seen.", "However, I can protect you from their curses, should you permit it."};
    node *openDoorNode6 = makeNode(paragraph97, 3, 30, NULL, NULL, "Will you accept my blessing [y/n]?: ");
    openDoorNode5 -> nextNode0 = openDoorNode6;
    // monster convert ending
    char *paragraph98[6] = {"", "A dark and warm presence embraces you.", "It unravels every fiber of your being, and you feel yourself being changed.", "Everything is black, so you can't tell exactly how you've changed, but you know the person you once were no longer exists.", "There is no going back.", "Ending 3/6: ~{A Fate Worse Than Death}~"};
    node *cursedEndNode = makeNode(paragraph98, 6, 30, NULL, NULL, NULL);
    openDoorNode6 -> nextNode0 = cursedEndNode;

    // post door nodes
    char *paragraph200[2] = {"", "You find yourself in a dark corridor once again."};
    node *progressedIntermediateNode1 = makeNode(paragraph200, 2, 30, NULL, NULL, NULL);
    openDoorNode6 -> nextNode1 = progressedIntermediateNode1;
    noHomeNode1 -> nextNode0 = progressedIntermediateNode1;

    startFromNode(introNode0);
    freeFromArray(nodeFreeArray);
}
