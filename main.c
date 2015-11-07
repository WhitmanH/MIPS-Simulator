#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 100
#define MAX_LENGTH 100

int main()
{
    printf("Hello world here's a test commit!\n");
    char *fileToRead = "function.asm";
    parseMIPS(fileToRead);


    printf("\nFinished Main");

    return 0;
}

void parseMIPS(char *file){
    char* MIPSInstructions[MAX_LENGTH][MAX_LENGTH];
    char* savedLabel[10];
    int* savedLabelIndex[10]; //HACK compare these two arrays to find index of label to return to it.
    char* actualMIPS[MAX_LENGTH];
    FILE *pointerFile;

    char *token;
    char *delimiter = " ,\t\r\n";

    pointerFile = fopen(file, "r");
    if(pointerFile == NULL){
        printf("file not found");
    }

    fseek(pointerFile, 0, SEEK_SET);
    int i = 0;
    int j = 0; //start from second part in the array, as 0 is only for the label.
    int sizeOfIndexArray = 0;
    while(i < MAX_LINE && fgets(MIPSInstructions[i], MAX_LINE, pointerFile)){
        for(token = strtok(MIPSInstructions[i], delimiter); token; token=strtok(NULL, delimiter)){
            if(token[0] == '#'){ // a comment
                break;
            }

            if(token[strlen(token)-1] == ':'){ //labels end with :
                savedLabel[j] = token;
                savedLabelIndex[j] = i;
                j = j + 1;
                sizeOfIndexArray++;
            }

            actualMIPS[i] = token;
            i++;
            printf("[%s]", token);
        }
        printf("\n");
    }
    fclose(pointerFile);
    int a=0;
    while(actualMIPS[a] != NULL){
        printf("[%s]", actualMIPS[a++]);
    }

    int b;
    for(b=0; b<sizeOfIndexArray; b++){
        printf("\nlabel %s is at index %d", savedLabel[b], savedLabelIndex[b]);
    }
}


//PREVIOUS IMPLEMENTATION USED THIS. Still keeping just in case.
/*
int isBlankLine(const char *line) {
    const char accept[]=" \t\r\n"; // any white spaces or simnly \n.
    return (strspn(line, accept) == strlen(line));
}

void trimWhiteSpace(char *line) {
    char *newLine = line;
    int l = strlen(newLine);

    while(isspace(newLine[l - 1])) newLine[--l] = 0;
    while(*newLine && isspace(*newLine)) ++newLine, --l;

    memmove(line, newLine, l + 1);
}
*/
