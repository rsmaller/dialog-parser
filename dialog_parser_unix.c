#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>
#include <fcntl.h>

struct termios canonical;
struct termios nonCanonical;

typedef struct node {
    char **paragraph;
    int paragraphLength;
    int speed;
    struct node *nextNode0;
    struct node *nextNode1;
    char *question;
} node;

node *makeNode(char **paragraph, int paragraphLength, int speed, node *nextNode0, node *nextNode1, char question[])
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode -> paragraph = (char **)malloc(sizeof(char *)*paragraphLength);
    for (int i=0;i<paragraphLength;i++)
    {
        newNode -> paragraph[i] = paragraph[i];
    }
    newNode -> speed = speed;
    newNode -> nextNode0 = nextNode0;
    newNode -> nextNode1 = nextNode1;
    newNode -> question = question;
    newNode -> paragraphLength = paragraphLength;
    // return newNode;
}

void setUpCanonicalStructs()
{
    tcgetattr(0, &canonical);
    tcgetattr(0, &nonCanonical);
    nonCanonical.c_lflag &= (~ICANON & ~ECHO);
}

void revertToCanonical()
{
    tcsetattr(0, TCSANOW, &canonical);
}

void makeNonCanonical()
{
    tcsetattr(0, TCSANOW, &nonCanonical);
}

void makeNonCanonicalUntilExit()
{
    tcsetattr(0, TCSANOW, &nonCanonical);
    atexit(&revertToCanonical);
}

void clearInputBuffer() // for use in non-canonical mode
{
    while (getc(stdin) != EOF){}
}

void waitForInput(int character)
{
    while (1)
    {
        char mychar = getc(stdin);
        if (mychar == character) // if ascii newline
        {
            break;
        }
    }
}

void sleepms(int milliseconds)
{
    usleep(milliseconds*1000);
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

void typeOutSentence(char sentence[], int speed)
{
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
            char *restOfString = sentence + (i*sizeof(char));
            printf("%s", restOfString);
            break;
        }
        printf("%c", sentence[i]);
        fflush(stdout);
    }
    waitForInput(10);
}

int askBool(char sentence[], int speed)
{
        system("clear");
        char input;
        int continue_count = 0;
        for (int i=0;i<(int)strlen(sentence);i++)
        {
            sleepms(speed);
            if (getc(stdin) == ' ')
            {
                char *restOfString = sentence + (i*sizeof(char));
                printf("%s", restOfString);
                break;
            }
            printf("%c", sentence[i]);
            fflush(stdout);
        }
        while (input != 'y' && input != 'n')
        {
            input = getc(stdin);
            if (input == 'y')
            {
                return 1;
            }
            else if (input == 'n')
            {
                return 0;
            }
        }
    }

void typeOutParagraph(char *paragraph[], int size, int speed) // speaker is first element in paragraph array.
{
    char *speaker = (char *)malloc((strlen(paragraph[0]) + 2) * sizeof(char)); 
    strcpy(speaker, paragraph[0]);
    strcat(speaker, ":");
    system("clear");
    for (int i=1;i<size;i++)
    {
        printf("%s\n", speaker);
        typeOutSentence(paragraph[i], speed);
        system("clear");
    }
    free(speaker);
}

void typeOutNode(node *nodeArg)
{
    typeOutParagraph(nodeArg -> paragraph, nodeArg -> paragraphLength, nodeArg -> speed);

}

void startFromNode(node *nodeArg)
{
    node *currentNode = nodeArg;
    typeOutNode(currentNode);
    while (currentNode -> nextNode0)
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

char *getMainCharacter()
{
    char *mc = (char *)malloc(sizeof(char)*201);
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

int main()
{
    char *mc = getMainCharacter();
    fcntl(0, F_SETFL, O_NONBLOCK);
    clearInputBuffer();
    system("clear");
    setUpCanonicalStructs();
    makeNonCanonicalUntilExit();
    char *paragraph[2] = {"Jason", "Hey Andy, what's your favorite MCR song?"};
    node *startingNode = makeNode(paragraph, 2, 30, NULL, NULL, NULL);
    char *paragraph2[2] = {"Andy", "I dunno, maybe Cemetery Drive?"};
    node *andyGenericNode1 = makeNode(paragraph2, 2, 30, NULL, NULL, NULL);
    startingNode -> nextNode0 = andyGenericNode1;
    char *paragraph3[2] = {"Jason", "Bro what? That song sucks ass! How can you even listen to that?"};
    node *andyGenericNode2 = makeNode(paragraph3, 2, 30, NULL, NULL, NULL);
    andyGenericNode1 -> nextNode0 = andyGenericNode2;
    char *paragraph4[3] = {"Andy", "HOW DARE YOU INSULT MY FAVORITE SONG!", "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"};
    node *andyGenericNode3 = makeNode(paragraph4, 3, 30, NULL, NULL, "Stick up for Andy [y/n]? ");
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
    char *paragraph9[3] = {"Jason", "Anyhow, today's been busy. I should probably head out.", "I'll see you guys around."};
    node *andyGenericNode4 = makeNode(paragraph9, 3, 30, NULL, NULL, NULL);
    andyNegativeNode2 -> nextNode0 = andyGenericNode4;
    andyPositiveNode2 -> nextNode0 = andyGenericNode4;
    startFromNode(startingNode);
}