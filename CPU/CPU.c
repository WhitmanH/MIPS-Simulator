//
// Created by Rui Tu on 11/9/15.
//


#include <stdio.h>
#include <string.h>

#define MAX_LINE 100
#define MAX_LENGTH 100

 int isBlankLine(const char *line) {
     const char accept[]=" \t\r\n"; // any white spaces or simnly \n.
     return (strspn(line, accept) == strlen(line));
 }
void fetch() {
    //PC_GLOABL = 0;

    // read the misp file and store instructions to the memory property
    char MIPSInstructions[MAX_LENGTH][5][15];
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
                //MIPSInstructions[i][0] = token;
                //token[strlen(token)+1] = '\0';
                lineHasLabel = 1;
                strcpy(MIPSInstructions[i][0], token);
            } else{
                //MIPSInstructions[i][p++] = token;
                //token[strlen(token)+1] = '\0';
                strcpy(MIPSInstructions[i][p++], token);
            }
        }
        if(lineHasLabel == 0){
            strcpy(MIPSInstructions[i][0], "NULL");
        }
        i++;
        p=1;
        lineHasLabel = 0;
    }
    printf("instruction = %s\n", MIPSInstructions[1][1]);
    
    int z,x;
    for(z = 0; z<29; z++){
        for(x=0; x<5; x++){
            printf("MIPSInstructions[%d][%d] = %s\n", z,x, MIPSInstructions[z][x]);
        }
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

/*
void cpu_run() {
    while (has_next_instruction()) {
        fetch();
        decode();
        execute();
    }
}
*/






