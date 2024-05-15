#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <conio.h>

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
}

void sleepms(int milliseconds)
{
    Sleep(milliseconds);
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
    char *dummy = (char *)malloc(1024);
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
        if (_kbhit() && getch() == ' ')
        {
            char *restOfString = sentence + (i*sizeof(char));
            printf(restOfString);
            break;
        }
        printf("%c", sentence[i]);
        fflush(stdout);
    }
    scanf("%c", dummy);
    free(dummy);
}

int askBool(char sentence[], int speed)
{
    while (1)
    {
        system("cls");
        char input;
        int continue_count = 0;
        for (int i=0;i<(int)strlen(sentence);i++)
        {
            sleepms(speed);
            if (_kbhit() && getch() == ' ')
            {
                char *restOfString = sentence + (i*sizeof(char));
                printf(restOfString);
                break;
            }
            printf("%c", sentence[i]);
            fflush(stdout);
        }
        scanf(" %c", &input);
        fflush(stdin);
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
    system("cls");
    for (int i=1;i<size;i++)
    {
        printf("%s\n", speaker);
        typeOutSentence(paragraph[i], speed);
        system("cls");
    }
    free(speaker);
}

void typeOutNode(node *nodeArg)
{
    typeOutParagraph(nodeArg -> paragraph, nodeArg -> paragraphLength, nodeArg -> speed);
    if (nodeArg -> question)
    {
        int outcome = askBool(nodeArg -> question, nodeArg -> speed);
        if (outcome)
        {
            typeOutNode(nodeArg -> nextNode1);
        }
        else
        {
            typeOutNode(nodeArg -> nextNode0);
        }
    }
    else if (nodeArg -> nextNode0)
    {
        typeOutNode(nodeArg -> nextNode0);
    }
}

void freeParagraph(char *paragraph[], int length)
{
    for (int i=0;i<length;i++)
    {
        free(paragraph[i]);
    }
}

int main()
{
    char mc[201];
    while (1)
    {
        char *buffer = (char *)malloc(sizeof(char)*2);
        system("cls");
        printf("Please enter your name: ");
        scanf("%200s", mc);
        if (strcmp(mc, "Jason") && strcmp(mc, "Andy"))
        {
            fflush(stdin);
            free(buffer);
            break;
        }
        else
        {
            printf("Invalid name. Please try again.");
            fflush(stdin);
            scanf("%c", buffer);
        }
    }

    char *paragraph[2] = {"Jason", "Hey Andy, what's your favorite MCR song?"};
    node *startingNode = makeNode(paragraph, 2, 30, NULL, NULL, NULL);
    freeParagraph(paragraph, 2);
    char *paragraph2[2] = {"Andy", "I dunno, maybe Cemetery Drive?"};
    node *andyGenericNode1 = makeNode(paragraph2, 2, 30, NULL, NULL, NULL);
    startingNode -> nextNode0 = andyGenericNode1;
    freeParagraph(paragraph2, 2);
    char *paragraph3[2] = {"Jason", "Bro what? That song sucks ass! How can you even listen to that?!"};
    node *andyGenericNode2 = makeNode(paragraph3, 2, 30, NULL, NULL, NULL);
    andyGenericNode1 -> nextNode0 = andyGenericNode2;
    freeParagraph(paragraph3, 2);
    char *paragraph4[3] = {"Andy", "HOW DARE YOU INSULT MY FAVORITE SONG!", "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"};
    node *andyGenericNode3 = makeNode(paragraph4, 3, 30, NULL, NULL, NULL);
    andyGenericNode2 -> nextNode0 = andyGenericNode3;
    freeParagraph(paragraph4, 2);

    // breakpoint for defining nodes versus typing them out.
    typeOutNode(startingNode);
}