//
// Created by Rui Tu on 11/9/15.
//

#include "CPU.h"
#include "../PC/PC.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 100
#define MAX_LENGTH 100
int pc;
void fetch() {
    //PC_GLOABL = 0;
    // read the misp file and store instructions to the memory property
    char MIPSInstructions[MAX_LENGTH][5];
    char buffer[MAX_LINE];
    char* actualMIPS[MAX_LENGTH];
    FILE *pointerFile;

    char *token;
    char *delimiter = " ,\t\r\n";

    pointerFile = fopen("function.asm", "r");
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
    // set program counter to the starting point



void decode() {
    // pass the instruction header to the control unit to get the correspondent signal
    // find out which instructions to execute
}


void execute() {
    //execute the instructions

}


void cpu_run() {
    while (has_next_instruction()) {
        fetch();
        decode();
        execute();
    }
}



