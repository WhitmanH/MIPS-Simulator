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
    FILE *pointerFile;

    char *token;
    char *delimiter = " ,\t\r\n";

    pointerFile = fopen(file, "r");
    if(pointerFile == NULL){
        printf("file not found");
    }

    fseek(pointerFile, 0, SEEK_SET);
    int i = 0; //start from second part in the array, as 0 is only for the label.
    while(i < MAX_LINE && fgets(MIPSInstructions[i], MAX_LINE, pointerFile)){
        for(token = strtok(MIPSInstructions[i], delimiter); token; token=strtok(NULL, delimiter)){
            if(token[0] == '#'){ // a comment
                break;
            }

            if(token[strlen(token)-1] == ':'){ //labels end with :
                //MIPSInstructions[0] = token;
                //break;
            }
            MIPSInstructions[i][strlen(MIPSInstructions[i])-1] = '\0';//get rid of end character.
            i++;
            printf("[%s]", token);
        }
        printf("\n");
    }
    fclose(pointerFile);

    //printf("example test = [%s]", MIPSInstructions[13][3]);

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
