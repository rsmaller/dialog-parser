#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

typedef struct node {
    char **paragraph;
    int paragraphLength;
    int speed;
    int openEndedQuestion;
    struct node *nextNode0;
    struct node *nextNode1;
    char *question;
    char *openEndedAnswer;
} node;

node *segFaultNode;

node *makeNode(char **paragraph, int paragraphLength, int speed, int openEndedness, char question[]) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode -> paragraph = (char **)malloc(sizeof(char *)*(unsigned int)paragraphLength);
    for (int i=0;i<paragraphLength;i++) {
        newNode -> paragraph[i] = paragraph[i];
    }
    newNode -> speed = speed;
    newNode -> nextNode0 = NULL;
    newNode -> nextNode1 = NULL;
    newNode -> openEndedQuestion = openEndedness;
    newNode -> openEndedAnswer = NULL;
    newNode -> question = question;
    newNode -> paragraphLength = paragraphLength;
    return newNode;
}

node *makeQuestionNode(char **paragraph, int paragraphLength, int speed, int openEndedness, char question[], char answer[]) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode -> paragraph = (char **)malloc(sizeof(char *)*(unsigned int)paragraphLength);
    for (int i=0;i<paragraphLength;i++) {
        newNode -> paragraph[i] = paragraph[i];
    }
    newNode -> speed = speed;
    newNode -> nextNode0 = NULL;
    newNode -> nextNode1 = NULL;
    newNode -> openEndedQuestion = openEndedness;
    newNode -> question = question; 
    newNode -> openEndedAnswer = answer;
    newNode -> paragraphLength = paragraphLength;
    return newNode;
}

void disableEcho() {
    DWORD consoleMode = ~ENABLE_LINE_INPUT; // 0 |
    HANDLE stdOutHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleMode(stdOutHandle, consoleMode);
}

void segfault() {
    printf("Segmentation fault: 11\n");
    exit(-1);
}

void sleepms(int milliseconds) {
    Sleep((DWORD)milliseconds);
}

void printEllipse() {
    for (int i=0;i<3;i++) {
        sleepms(360);
        printf(".");
        fflush(stdout);
    }
}

void typeOutSentence(char sentence[], int speed) {
    char *dummy = (char *)malloc(1024);
    int continue_count = 0;
    for (int i=0;i<(int)strlen(sentence);i++) {
        if (sentence[i] == '{' && sentence[i+1] == '.' && sentence[i+2] == '.' && sentence[i+3] == '.' && sentence[i+4] == '}') {
            printEllipse();
            continue_count = 5;
        }
        if (continue_count) {
            continue_count -= 1;
            continue;
        }
        // makeTypeNoise(speed);
        sleepms(speed);
        if (_kbhit() && getch() == ' ') {
            char *restOfString = sentence + (sizeof(char) * (unsigned int)i);
            printf("%s", restOfString);
            break;
        }
        printf("%c", sentence[i]);
        fflush(stdout);
    }
    char currentChar = getch();
    while (!_kbhit() && currentChar != '\r') { // hang until enter key is pressed
        if (currentChar == 3) { // CTRL-C
            exit(-1);
        }
        currentChar = getch();
    } 
    free(dummy);
}

char *askOpenQuestion(char sentence[], int speed) {
    char *dummy = (char *)malloc(1024);
    int continue_count = 0;
    for (int i=0;i<(int)strlen(sentence);i++) {
        if (sentence[i] == '{' && sentence[i+1] == '.' && sentence[i+2] == '.' && sentence[i+3] == '.' && sentence[i+4] == '}') {
            printEllipse();
            continue_count = 5;
        }
        if (continue_count) {
            continue_count -= 1;
            continue;
        }
        sleepms(speed);
        if (_kbhit() && getch() == ' ') {
            char *restOfString = sentence + (sizeof(char) * (unsigned int)i);
            printf("%s", restOfString);
            break;
        }
        printf("%c", sentence[i]);
        fflush(stdout);
    }
    fgets(dummy, 1024, stdin);
    return dummy;
}

int askBool(char sentence[], int speed, int openEndedness, char answer[]) {
    char *userInput;
    if (!openEndedness && !answer) {
        while (1) {
            system("cls");
            char input;
            for (int i=0;i<(int)strlen(sentence);i++) {
                sleepms(speed);
                if (_kbhit() && getch() == ' ') {
                    char *restOfString = sentence + (sizeof(char) * (unsigned int)i);
                    printf("%s", restOfString);
                    break;
                }
                printf("%c", sentence[i]);
                fflush(stdout);
            }
            scanf(" %c", &input);
            fflush(stdin);
            if (input == 'y') {
                return 1;
            } else if (input == 'n') {
                return 0;
            }
        }
    } else {
        userInput = askOpenQuestion(sentence, speed);
        return !strcmp(userInput, answer);
    }
}

void typeOutParagraph(char *paragraph[], int size, int speed) {// speaker is first element in paragraph array.
    char *speaker = (char *)malloc((strlen(paragraph[0]) + 2) * sizeof(char)); 
    strcpy(speaker, paragraph[0]);
    strcat(speaker, ":");
    system("cls");
    for (int i=1;i<size;i++) {
        if (strcmp(speaker, ":")) {
        printf("%s\n", speaker);
        }
        fflush(stdin); // prevent auto-skipping dialog
        typeOutSentence(paragraph[i], speed);
        system("cls");
    }
    free(speaker);
}

void typeOutNode(node *nodeArg) {
    typeOutParagraph(nodeArg -> paragraph, nodeArg -> paragraphLength, nodeArg -> speed);
    if (nodeArg == segFaultNode) {
        segfault();
    }
}

void startFromNode(node *nodeArg) {
    node *currentNode = nodeArg;
    typeOutNode(currentNode);
    while (currentNode -> nextNode0 || currentNode -> nextNode1) {
        if (currentNode -> question) {
            int outcome = askBool(currentNode -> question, currentNode -> speed, currentNode -> openEndedQuestion, currentNode -> openEndedAnswer);
            if (outcome) {
                currentNode = currentNode -> nextNode1;
            } else {
                currentNode = currentNode -> nextNode0;
            }
        } else {
            currentNode = currentNode -> nextNode0;
        }
        typeOutNode(currentNode);
    }
}

void freeParagraph(char *paragraph[], int length) {
    for (int i=0;i<length;i++) {
        free(paragraph[i]);
    }
}

int main() {
    // segfault();
    disableEcho();
    char mc[201];
    while (1) {
        system("cls");
        strcpy(mc, askOpenQuestion("Please enter your name: ", 0));
        if (strcmp(mc, "Jason") && strcmp(mc, "Andy")) {
            fflush(stdin);
            break;
        } else {
            printf("Invalid name. Please try again.");
            fflush(stdin);
        }
    }

    char *introParagraph[2] = {"", "You walk into the food court and see Andy and Jason sitting together, talking about music."};
    node *introNode0 = makeNode(introParagraph, 2, 30, 0, "Join them [y/n]?: ");
    char *paragraph1[2] = {"Jason", "Hey Andy, what's your favorite MCR song?"};
    node *introNode1 = makeNode(paragraph1, 2, 30, 0, NULL);
    introNode0 -> nextNode1 = introNode1;

    char *paragraph2[2] = {"Andy", "Cemetery Drive, no doubt."};
    node *andyGenericNode1 = makeNode(paragraph2, 2, 30, 0, NULL);
    introNode1 -> nextNode0 = andyGenericNode1;

    char *endParagraph0[5] = {"", "Why didn't you sit with them?", "What the hell is wrong with you?", "Stop being a dick.", "Ending 1/xxx: ~{You're An Asshole}~"};
    node *ending0 = makeNode(endParagraph0, 5, 30, 0, NULL);
    introNode0 -> nextNode0 = ending0;

    char *paragraph3[2] = {"Jason", "Bro what? That song sucks ass! How can you even listen to that?"};
    node *andyGenericNode2 = makeNode(paragraph3, 2, 30, 0, NULL);
    andyGenericNode1 -> nextNode0 = andyGenericNode2;

    char *paragraph4[3] = {"Andy", "HOW DARE YOU INSULT MY FAVORITE SONG!", "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"};
    node *andyGenericNode3 = makeNode(paragraph4, 3, 30, 0, "Stick up for Andy [y/n]?: ");
    andyGenericNode2 -> nextNode0 = andyGenericNode3;

    char *paragraph5[2] = {mc, "Hey, I actually like that song."};
    node *andyPositiveNode1 = makeNode(paragraph5, 2, 30, 0, NULL);
    andyGenericNode3 -> nextNode1 = andyPositiveNode1;

    char *paragraph6[2] = {mc, "Gotta agree with Jason. Song sucks."};
    node *andyNegativeNode1 = makeNode(paragraph6, 2, 30, 0, NULL);
    andyGenericNode3 -> nextNode0 = andyNegativeNode1;

    char *paragraph7[3] = {"Jason", "At least you have someone to share your terrible music taste with, Andy.", "I didn't think someone like that existed."};
    node *andyPositiveNode2 = makeNode(paragraph7, 3, 30, 0, NULL);
    andyPositiveNode1 -> nextNode0 = andyPositiveNode2;

    char *paragraph8[2] = {"Jason", "I'm glad someone shares my cultured opinion."};
    node *andyNegativeNode2 = makeNode(paragraph8, 2, 30, 0, NULL);
    andyNegativeNode1 -> nextNode0 = andyNegativeNode2;

    char *paragraph9[3] = {"Jason", "Anyhow, today's going to be busy. I should probably head to the desk now.", "I'll see you guys around."};
    node *andyGenericNode4 = makeNode(paragraph9, 3, 30, 0, NULL);
    andyNegativeNode2 -> nextNode0 = andyGenericNode4;
    andyPositiveNode2 -> nextNode0 = andyGenericNode4;

    char *paragraph10[2] = {"", "After Jason gets up and leaves, you notice he forgot one of his notebooks and left it on the table."};
    node *andyGenericNode5 = makeNode(paragraph10, 2, 30, 0, "Read the notebook [y/n]?: ");
    andyGenericNode4 -> nextNode0 = andyGenericNode5;

    // start of don't read node.
    char *paragraph11[6] = {"", "You open the notebook and read what appears to be complete gibberish.", "The words \"k talbloc nemlec nac\" are marked on the page in dark yellow ink.",
    "Upon flipping to the second page, you notice it has a familiar yet unpleasant scent, but you can't quite place it...", "The other pages are filled with random bits of architecture and statistics notes that are of no interest to you.", 
    "In the half hour or so you spent fiddling through Jason's personal business instead of eating lunch, your class starts."};
    node *readJasonNode1 = makeNode(paragraph11, 6, 30, 0, NULL);
    andyGenericNode5 -> nextNode1 = readJasonNode1;

    char *paragraph12[2] = {mc, "Shit, I'm late for class! Gotta go!"};
    node *readJasonNode2 = makeNode(paragraph12, 2, 30, 0, NULL);
    readJasonNode1 -> nextNode0 = readJasonNode2;

    char *paragraph13[2] = {"", "You run to class as fast as you possibly can to soften the blow of being late."};
    node *readJasonNode3 = makeNode(paragraph13, 2, 30, 0, NULL);
    readJasonNode2 -> nextNode0 = readJasonNode3;

    char *paragraph14[2] = {mc, "Did I make it in time? I wonder what the teacher is on about..."};
    node *readJasonNode4 = makeNode(paragraph14, 2, 30, 0, NULL);
    readJasonNode3 -> nextNode0 = readJasonNode4;

    char *paragraph16[4] = {"", "You sit down and notice the classroom is less crowded than usual.", "Seems like some people chose not to come to class today.", "The emptiness of the classroom is unsettling."};
    node *readJasonNode5 = makeNode(paragraph16, 4, 30, 0, NULL);
    readJasonNode4 -> nextNode0 = readJasonNode5;

    // branch aside from read jason node. the don't read branch starts here.
    char *paragraph17[2] = {"", "You leave Jason's notebook on the lunch table. Something about it makes you feel uneasy."};
    node *dontReadJasonNode1 = makeNode(paragraph17, 2, 30, 0, NULL);
    andyGenericNode5 -> nextNode0 = dontReadJasonNode1;

    char *paragraph18[2] = {"Andy", "Oh, Jason left his notebook, huh?"};
    node *dontReadJasonNode2 = makeNode(paragraph18, 2, 30, 0, NULL);
    dontReadJasonNode1 -> nextNode0 = dontReadJasonNode2;

    char *paragraph19[2] = {mc, "Yeah. There's something I don't like about it."};
    node *dontReadJasonNode3 = makeNode(paragraph19, 2, 30, 0, NULL);
    dontReadJasonNode2 -> nextNode0 = dontReadJasonNode3;

    char *paragraph20[2] = {"Andy", "Interesting. I'll take your word for it."};
    node *dontReadJasonNode4 = makeNode(paragraph20, 2, 30, 0, NULL);
    dontReadJasonNode3 -> nextNode0 = dontReadJasonNode4;

    char *paragraph21[6] = {"", "You sit and eat your lunch (whatever that might be because I have no idea) with Andy.", "You feel nourished and ready for the challenges ahead.",
    "As you finish your lunch, you see that it is time for class, so you head over a little early to get a headstart.", 
    "You take out your textbook and plop it on the table. It makes a loud thump.", "As you finish setting up your desk and getting everything sorted, class starts..."};
    node *dontReadJasonNode5 = makeNode(paragraph21, 6, 30, 0, NULL);
    dontReadJasonNode4 -> nextNode0 = dontReadJasonNode5;

    // collapse into classroom talk.
    char *paragraph81[3] = {"John D. Professor", "Listen up, kids!", "Today's not going to be a super eventful day. Just turn to page 250 in your textbooks."};
    node *intermediateNode1 = makeNode(paragraph81, 3, 30, 0, NULL);
    readJasonNode5 -> nextNode0 = intermediateNode1;
    dontReadJasonNode5 -> nextNode0 = intermediateNode1;

    char *paragraph82[6] = {"", "You turn to page 250 in your textbook.", "\"Chapter 15, Section 2: The Gentle Art of Octeeel Grift\"", "The words on the page don't make sense to you.", "\"Jake neentjeneisdotrrtkc. Hanson trod fleecloco octeeel grift. Lit@tmr detox my@ceins.\"", "Gibberish fills the entire page, which ends with \"babe removal\"."};
    node *intermediateNode2 = makeNode(paragraph82, 6, 30, 0, NULL);
    intermediateNode1 -> nextNode0 = intermediateNode2;

    char *paragraph83[2] = {"Nhu", "This is stupid. I'm taking a nap."};
    node *intermediateNode3 = makeNode(paragraph83, 2, 30, 0, NULL);
    intermediateNode2 -> nextNode0 = intermediateNode3;

    char *paragraph84[4] = {"", "You have no idea who Nhu is or what she is doing in this classroom, but she fell asleep faster than you could look over to her while she was talking.", "Her friends seem unfazed, though, and you notice one of them drawing suspicious fan art of some character named \"Joker\" while agressively mumbling about an orange scented hand soap.", "There are a couple other people in the room, but you firstly overhear orange hand soap girl asking what \"maybe\" means."};
    node *intermediateNode4 = makeNode(paragraph84, 4, 30, 0, NULL);
    intermediateNode3 -> nextNode0 = intermediateNode4;

    char *paragraph85[2] = {"Aariba", "Ah yes, I see.. mhm... mhm.."};
    node *intermediateNode5 = makeNode(paragraph85, 2, 30, 0, NULL);
    intermediateNode4 -> nextNode0 = intermediateNode5;

    char *paragraph86[3] = {"Brain", "...", "(My Receptacle isn't at full power... I must lay low.)"};
    node *intermediateNode6 = makeNode(paragraph86, 3, 30, 0, NULL);
    intermediateNode5 -> nextNode0 = intermediateNode6;

    char *paragraph87[3] = {"", "Apparently you can read thoughts. Who knew?", "After your mind reading session, your class ends. It's time to push forward."};
    node *intermediateNode7 = makeNode(paragraph87, 3, 30, 0, "Head home [y/n]?: ");
    intermediateNode6 -> nextNode0 = intermediateNode7;

    // (don't) go home
    char *paragraph88[5] = {"", "You decide to head home.", "Your house is enveloped in a very distinct smell.", "The odor in your abode manifests into something physical, although you can't make out what.", "It crawls up your body and consumes you as you utter your final words..."};
    node *homeNode1 = makeNode(paragraph88, 5, 30, 0, NULL);
    intermediateNode7 -> nextNode1 = homeNode1;

    char *paragraph89[2] = {mc, "Is that... a piss monster...?"};
    node *homeNode2 = makeNode(paragraph89, 2, 30, 0, NULL);
    homeNode1 -> nextNode0 = homeNode2;

    char *paragraph90[3] = {"", "You got pissed on. What a way to go out." ,"Ending 2/xxx: ~{Golden Shower}~"};
    node *homeNodeEnd = makeNode(paragraph90, 3, 30, 0, NULL);
    homeNode2 -> nextNode0 = homeNodeEnd;

    // don't go home
    char *paragraph91[5] = {"", "You decide not to head home and loiter around school for a while.", "As you are walking around, you notice a highly decorated door with what looks like a marble handle.",
    "It's surprising you haven't noticed this before...", "As you step closer, you feel a warm and welcoming presence behind the door."};
    node *noHomeNode1 = makeNode(paragraph91, 5, 30, 0, "Open the door [y/n]?: ");
    intermediateNode7 -> nextNode0 = noHomeNode1;

    // open the door ending
    char *paragraph92[2] = {"", "You open the door..."};
    node *openDoorNode1 = makeNode(paragraph92, 2, 30, 0, NULL);
    noHomeNode1 -> nextNode1 = openDoorNode1;

    char *paragraph93[2] = {"The Elder God, Ryab", "I've been expecting you."};
    node *openDoorNode2 = makeNode(paragraph93, 2, 30, 0, NULL);
    openDoorNode1 -> nextNode0 = openDoorNode2;

    char *paragraph94[4] = {"", "You feel an overwhelming presence from this man. It's nothing like you've ever experienced before.", "Yet, somehow, you feel comfortable and safe.", "You are at a loss for words."};
    node *openDoorNode3 = makeNode(paragraph94, 4, 30, 0, NULL);
    openDoorNode2 -> nextNode0 = openDoorNode3;

    char *paragraph95[3] = {"The Elder God's Chosen, Angy", "The Elder God has summoned you for a reason.", "Do not disappoint him."};
    node *openDoorNode4 = makeNode(paragraph95, 3, 30, 0, NULL);
    openDoorNode3 -> nextNode0 = openDoorNode4;

    char *paragraph96[2] ={mc, "And what might that reason be?"};
    node *openDoorNode5 = makeNode(paragraph96, 2, 30, 0, NULL);
    openDoorNode4 -> nextNode0 = openDoorNode5;

    char *paragraph97[3] = {"The Elder God, Ryab", "There are ancient evils inhabiting this establishment, like few you've ever seen.", "However, I can protect you from their curses, should you permit it."};
    node *openDoorNode6 = makeNode(paragraph97, 3, 30, 0, "Will you accept my blessing [y/n]?: ");
    openDoorNode5 -> nextNode0 = openDoorNode6;
    
    // monster conversion ending
    char *paragraph98[6] = {"", "A dark and warm presence embraces you.", "It unravels every fiber of your being, and you feel yourself being changed.", "Everything is black, so you can't tell exactly how you've changed, but you know the person you once were no longer exists.", "There is no going back.", "Ending 3/6: ~{An Eternal Fate Stranger Than Death}~"};
    node *cursedEndNode = makeNode(paragraph98, 6, 30, 0, NULL);
    openDoorNode6 -> nextNode0 = cursedEndNode;

    // post door nodes
    char *paragraph200[7] = {"", "You find yourself in a dark corridor once again.", "The ground around you feels somewhat.. jagged?", "You can't exactly place what the feeling is, though there is an air of instability and uncertainty.", "This hall is darker than you remember it being.", "You walk down the hall for a little bit hoping to catch a glimpse of something recognizable.", "What you find is somewhat unexpected..."};
    node *progressedIntermediateNode1 = makeNode(paragraph200, 7, 30, 0, NULL);
    openDoorNode6 -> nextNode1 = progressedIntermediateNode1;
    noHomeNode1 -> nextNode0 = progressedIntermediateNode1;

    char *paragraph201[3] = {"Andy", "Hey, what are you doing here?", "I didn't expect to run into you this late."};
    node *andyProgressedNode1 = makeNode(paragraph201, 3, 30, 0, NULL);
    progressedIntermediateNode1 -> nextNode0 = andyProgressedNode1;

    char *paragraph202[3] = {mc, "I'm not sure why or how I ended up here.", "I kinda just.. did."};
    node *andyProgressedNode2 = makeNode(paragraph202, 3, 30, 0, NULL);
    andyProgressedNode1 -> nextNode0 = andyProgressedNode2;

    char *paragraph203[2] = {"Andy", "Well, if you say so."};
    node *andyProgressedNode3 = makeNode(paragraph203, 2, 30, 0, NULL);
    andyProgressedNode2 -> nextNode0 = andyProgressedNode3;

    char *paragraph204[3] = {"", "Andy falls uncomfortably silent.", "He's.. breaking into square-shaped pieces?"};
    node *andyProgressedNode4 = makeNode(paragraph204, 3, 30, 0, NULL);
    andyProgressedNode3 -> nextNode0 = andyProgressedNode4;

    char *paragraph205[2] = {mc, "Hey Andy, are you okay?"};
    node *andyProgressedNode5 = makeNode(paragraph205, 2, 30, 0, NULL);
    andyProgressedNode4 -> nextNode0 = andyProgressedNode5;

    char *paragraph206[2] = {"Andy", "yh_, I feal finE"};
    node *andyGlitchNode1 = makeNode(paragraph206, 2, 0, 0, NULL);
    andyProgressedNode5 -> nextNode0 = andyGlitchNode1;

    char *paragraph207[5] = {"", "You examine Andy closely, interested in his current condition.", "As you look, reality sets in. Something is terribly wrong, yet...", "It's fixable.. this is something you've seen before.", "It's the same thing Brian stores in his Receptacle."};
    node *andyGlitchNode2 = makeNode(paragraph207, 5, 30, 0, NULL);
    andyGlitchNode1 -> nextNode0 = andyGlitchNode2;

    char *paragraph208[3] = {mc, "Ancient, arcane power..", "I must use it to save him."};
    node *andyGlitchNode3 = makeNode(paragraph208, 3, 30, 0, "gcc -o test -fno-stack-protector -O3 [y/n]?: ");
    andyGlitchNode2 -> nextNode0 = andyGlitchNode3;

    // segfault ending
    char *paragraph209[3] = {"", "You fail to summon the power to save Andy from the disease ripping at his soul.", "The leaked memory consumes everything in its wake, leaving nothing left. Reality is broken.."};
    node *segFaultEnd = makeNode(paragraph209, 3, 30, 0, NULL);
    segFaultNode = segFaultEnd;
    andyGlitchNode3 -> nextNode0 = segFaultEnd;
        
    char *paragraph210[3] = {"", "It burns, but you're able to prevent Andy's memory from leaking everywhere and destroying everything.", "He seems to have gone mostly back to normal."};
    node *andyFixNode1 = makeNode(paragraph210, 3, 30, 0, NULL);
    andyGlitchNode3 -> nextNode1 = andyFixNode1;

    char *paragraph211[2] = {"Andy", "Hey, something smell funny?"};
    node *andyFixNode2 = makeNode(paragraph211, 2, 30, 0, NULL);
    andyFixNode1 -> nextNode0 = andyFixNode2;

    char *paragraph212[3] = {"", "On second thought, maybe not.", "Andy did not notice his memory leak at all."};
    node *andyFixNode3 = makeNode(paragraph212, 3, 30, 0, NULL);
    andyFixNode2 -> nextNode0 = andyFixNode3;

    char *paragraph213[2] = {mc, "Something else must be going on here..."};
    node *andyFixNode4 = makeNode(paragraph213, 2, 30, 0, NULL);
    andyFixNode3 -> nextNode0 = andyFixNode4;

    char *paragraph214[2] = {"Andy", "I have no idea what you're talking about, but I'll take your word for it."};
    node *andyFixNode5 = makeNode(paragraph214, 2, 30, 0, NULL);
    andyFixNode4 -> nextNode0 = andyFixNode5;

    char *paragraph215[2] = {"Jason", "You should know what he's talking about, Andy."};
    node *jasonFinalBossNode1 = makeNode(paragraph215, 2, 30, 0, NULL);
    andyFixNode5 -> nextNode0 = jasonFinalBossNode1;

    char *paragraph216[2] = {"", "Jason appeared out of nowhere it seems. How curious."};
    node *jasonFinalBossNode2 = makeNode(paragraph216, 2, 30, 0, NULL);
    jasonFinalBossNode1 -> nextNode0 = jasonFinalBossNode2;

    char *paragraph217[2] = {"Andy", "When did you get here?"};
    node *jasonFinalBossNode3 = makeNode(paragraph217, 2, 30, 0, NULL);
    jasonFinalBossNode2 -> nextNode0 = jasonFinalBossNode3;

    char *paragraph218[2] = {"Jason", "You won't be worrying about that in a moment."};
    node *jasonFinalBossNode4 = makeNode(paragraph218, 2, 30, 0, NULL);
    jasonFinalBossNode3 -> nextNode0 = jasonFinalBossNode4;

    char *paragraph219[5] = {"", "Before you or Andy could react, Jason let out a volley of attacks.", "The attacks were pixelated and jagged.", "You raised your arms to defend yourself and Andy did the same.", "As you both held out, Jason gave a sinister look."};
    node *jasonFinalBossNode5 = makeNode(paragraph219, 5, 30, 0, NULL);
    jasonFinalBossNode4 -> nextNode0 = jasonFinalBossNode5;

    char *paragraph220[3] = {"Jason", "Have you figured it out yet?", "What's going on around you?"};
    node *jasonFinalBossNode6 = makeNode(paragraph220, 3, 30, 0, NULL);
    jasonFinalBossNode5 -> nextNode0 = jasonFinalBossNode6;

    char *paragraph221[3] = {"", "Well, have you?", "I mean, don't just wait around for me to tell you. Figure it out!"};
    node *jasonFinalBossNode7 = makeQuestionNode(paragraph221, 3, 30, 1, "The thing we need to kill Jason.. his true weakness is?: ", "mental block\n");
    jasonFinalBossNode6 -> nextNode0 = jasonFinalBossNode7;

    char *paragraph222[2] = {"", "You failed."};
    node *failedNode1 = makeNode(paragraph222, 2, 0, 0, NULL);
    jasonFinalBossNode7 -> nextNode0 = failedNode1;

    char *paragraph400 [2] = {"", "You succeeded."};
    node *succeededNode1 = makeNode(paragraph400, 2, 0, 0, NULL);
    jasonFinalBossNode7 -> nextNode1 = succeededNode1;

    startFromNode(jasonFinalBossNode7);
}