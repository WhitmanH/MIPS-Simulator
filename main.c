#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 100
#define MAX_LENGTH 100

void parseMIPS(char *file){
    char MIPSInstructions[MAX_LENGTH][5];
    char buffer[MAX_LINE];
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
    int p = 1;
    int sizeOfIndexArray = 0;
    while(i < MAX_LINE && fgets(buffer, MAX_LINE, pointerFile)){
        char temp[5][100];
        for(token = strtok(buffer, delimiter); token; token=strtok(NULL, delimiter)){
            if(token[0] == '#'){ // a comment
                break;
            }

            else if(token[strlen(token)-1] == ':'){ //labels end with :
                //MIPSInstructions[i][0] = token;
                strncpy(&MIPSInstructions[i][0], token, 10);
            } else{
                //MIPSInstructions[i][p++] = token;
                strncpy(&MIPSInstructions[i][p++], token, 10);
                printf("%s\n", token);
            }
        }
        i++;
        p = 1;
    }

    fclose(pointerFile);
    }

    /*
    int a=0;
    int b = 0;
    while(actualMIPS[a] != NULL){
        printf("[%s]", actualMIPS[a++]);
    }
	/*
    int b;
    for(b=0; b<sizeOfIndexArray; b++){
        printf("\nlabel %s is at index %d", savedLabel[b], savedLabelIndex[b]);
    }*/

    //printf("%s\n", MIPSInstructions[0]);


int main()
{
    printf("Hello world here's a test commit!\n");
    char *fileToRead = "fibonacci.asm";
    parseMIPS(fileToRead);


    printf("\nFinished Main");

    return 0;
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
