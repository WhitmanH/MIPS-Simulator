//
// Created by Rui Tu on 11/9/15.
//

#include "CPU.h"
#include "../PC/PC.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../memory/memory.h"
#include "../PC/PC.h"

#define MAX_LINE 100
#define MAX_LENGTH 100
int INSTRUCTION_MEMORY_GLOBAL_LENGTH;


 int isBlankLine(const char *line) {
     const char accept[]=" \t\r\n"; // any white spaces or simnly \n.
     return (strspn(line, accept) == strlen(line));
 }
void fetch() {
    //PC_GLOBAL = 0;
    // read the misp file and store instructions to the memory property
    char INSTRUCTION_MEMORY_GLOBAL[100][5][15];
    char buffer[MAX_LINE];
    char* actualMIPS[MAX_LENGTH];
    FILE *pointerFile;

    char *token;
    char *delimiter = " ,\t\r\n";

    pointerFile = fopen("/Users/rui/Google Drive/UO/Fall 2015/CIS 314/Processor-Assignment1/MispTestFiles/bubble.asm", "r");
   // pointerFile = fopen("/Users/CamelTop/Desktop/Processor-Assignment1/mispTestFiles/gcd.asm", "r");
    if(pointerFile == NULL){
        printf("file not found");
    }

    fseek(pointerFile, 0, SEEK_SET);
    int i = 0;
    int p = 1;
    int sizeOfIndexArray = 0;
    int lineHasLabel = 0;
    while(i < MAX_LINE && fgets(buffer, MAX_LINE, pointerFile)){
        if(buffer[0] == '\n' || buffer[0] == '#' || buffer[0] == '0' || buffer[0] =='\r'){
            continue;
        }
        if(buffer[0] == '\t' && strlen(buffer) == 0){
            continue;
        }
        if(isBlankLine(buffer)){
            continue;
        }
        for(token = strtok(buffer, delimiter); token; token=strtok(NULL, delimiter)){
            if(token[0] == '#'){ // a comment
                break;
            }
            else if(token[strlen(token)-1] == ':'){ //labels end with :
                //INSTRUCTION_MEMORY_GLOBAL[i][0] = token;
                //token[strlen(token)+1] = '\0';
                lineHasLabel = 1;
                strcpy(INSTRUCTION_MEMORY_GLOBAL[i][0], token);
            } else{
                //INSTRUCTION_MEMORY_GLOBAL[i][p++] = token;
                //token[strlen(token)+1] = '\0';
                strcpy(INSTRUCTION_MEMORY_GLOBAL[i][p++], token);
            }
        }
        if(lineHasLabel == 0){
            strcpy(INSTRUCTION_MEMORY_GLOBAL[i][0], "NULL");
        }
        i++;
        p=1;
        lineHasLabel = 0;
    }

    INSTRUCTION_MEMORY_GLOBAL_LENGTH = i;
    printf("\nCHECK ME OUT %d\n", INSTRUCTION_MEMORY_GLOBAL_LENGTH);

    int z,x;
    for(z = 0; z<29; z++){
        for(x=0; x<5; x++){
            printf("INSTRUCTION_MEMORY_GLOBAL[%d][%d] = %s\n", z,x, INSTRUCTION_MEMORY_GLOBAL[z][x]);
        }
    }
    
    
    fclose(pointerFile);
}

// okg

void decode() {
    // pass the instruction header to the control unit to get the correspondent signal
    // find out which instructions to execute
}


void execute() {
    //execute the instructions

}

/*
void cpu_run() {
    initialize_data_memory();
    while (has_next_instruction()) {
        fetch();
        decode();
        execute();
    }
}
*/
