#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 100
#define MAX_LENGTH 100

int main()
{
    printf("Hello world here's a test commit!\n");
    FILE *pointerFile;
    char buffer[MAX_LINE]; // max length of one line of code
    char* instructionMIPS[MAX_LENGTH]; //100 lines of code

    pointerFile = fopen("/Users/rui/Google Drive/UO/Fall 2015/CIS 314/Processor-Assignment1/MispTestFiles/function.asm", "r"); //using the functions MIPS code to test.
    if(!pointerFile){
        printf("File not found");
        return 0;
    }

    int i = 0;
    while (fgets(buffer, MAX_LINE, pointerFile) != NULL){
        printf("%s", buffer);
        instructionMIPS[i] = strdup(buffer); //string duplicate
        i++;
    }
    fclose(pointerFile);

    //checking to see if saved to instructionMIPS
    printf("check to see if a line is saved to array: %s", instructionMIPS[12]);
    printf("\ndone");

    return 0;
}
