#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "../PC/PC.h"
#include "../CPU/CPU.h"
#include "../CPU/CPU.c"
#include "../CPU/executeHelpers/executeHelpers.c"
extern int INSTRUCTION_MEMORY_GLOBAL_LENGTH;
extern int PC_GLOBAL;
// TODO: implement the control logic that tell other unit which instruction to execute.

void control_logic() {
    // since we got instruction we increment the PC_GLOBAL
    char INSTRUCTION_MEMORY_GLOBAL[100][5][15];
    printf("Length of instructions: %d\n", INSTRUCTION_MEMORY_GLOBAL_LENGTH);
    int PC_GLOBAL = 0;
    //goto_next_instruction();
    
    while(PC_GLOBAL < INSTRUCTION_MEMORY_GLOBAL_LENGTH -1){
        if(strcmp(INSTRUCTION_MEMORY_GLOBAL[PC_GLOBAL][1], "add") == 0){
            exec_add(INSTRUCTION_MEMORY_GLOBAL[PC_GLOBAL][2], INSTRUCTION_MEMORY_GLOBAL[PC_GLOBAL][3], INSTRUCTION_MEMORY_GLOBAL[PC_GLOBAL][4]);
            printf("\ndebug: we are adding registers: %s and %s to register: %s", INSTRUCTION_MEMORY_GLOBAL[PC_GLOBAL][3], INSTRUCTION_MEMORY_GLOBAL[PC_GLOBAL][4], INSTRUCTION_MEMORY_GLOBAL[PC_GLOBAL][2]);
            PC_GLOBAL++;
        }
        else if(strcmp(INSTRUCTION_MEMORY_GLOBAL[PC_GLOBAL][1], "addi") == 0){
            printf("\ndebug: we are adding registers: %s and %s to register: %s", INSTRUCTION_MEMORY_GLOBAL[PC_GLOBAL][3], INSTRUCTION_MEMORY_GLOBAL[PC_GLOBAL][4], INSTRUCTION_MEMORY_GLOBAL[PC_GLOBAL][2]);
            exec_addi(INSTRUCTION_MEMORY_GLOBAL[PC_GLOBAL][2], INSTRUCTION_MEMORY_GLOBAL[PC_GLOBAL][3], INSTRUCTION_MEMORY_GLOBAL[PC_GLOBAL][4]);
            PC_GLOBAL++;
        }
        else if(strcmp(INSTRUCTION_MEMORY_GLOBAL[PC_GLOBAL][1], "sub") == 0){
            exec_sub(INSTRUCTION_MEMORY_GLOBAL[PC_GLOBAL][2], INSTRUCTION_MEMORY_GLOBAL[PC_GLOBAL][3], INSTRUCTION_MEMORY_GLOBAL[PC_GLOBAL][4]);
            PC_GLOBAL++;
        }
        else if(strcmp(INSTRUCTION_MEMORY_GLOBAL[PC_GLOBAL][1], "slt") == 0){
            exec_slt(INSTRUCTION_MEMORY_GLOBAL[PC_GLOBAL][2], INSTRUCTION_MEMORY_GLOBAL[PC_GLOBAL][3], INSTRUCTION_MEMORY_GLOBAL[PC_GLOBAL][4]);
            PC_GLOBAL++;
        }
        else if(strcmp(INSTRUCTION_MEMORY_GLOBAL[PC_GLOBAL][1], "sltu") == 0){
            exec_sltu(INSTRUCTION_MEMORY_GLOBAL[PC_GLOBAL][2], INSTRUCTION_MEMORY_GLOBAL[PC_GLOBAL][3], INSTRUCTION_MEMORY_GLOBAL[PC_GLOBAL][4]);
            PC_GLOBAL++;
        }
        else if(strcmp(INSTRUCTION_MEMORY_GLOBAL[PC_GLOBAL][1], "lw") == 0){
            PC_GLOBAL++;
        }
        else if(strcmp(INSTRUCTION_MEMORY_GLOBAL[PC_GLOBAL][1], "sw") == 0){
            PC_GLOBAL++;
        }
        else if(strcmp(INSTRUCTION_MEMORY_GLOBAL[PC_GLOBAL][1], "beq") == 0){
            //branch_equal_to(INSTRUCTION_MEMORY_GLOBAL[PC_GLOBAL][2], INSTRUCTION_MEMORY_GLOBAL[PC_GLOBAL][3], INSTRUCTION_MEMORY_GLOBAL[PC_GLOBAL][4]);
            PC_GLOBAL++;
        }
        else if(strcmp(INSTRUCTION_MEMORY_GLOBAL[PC_GLOBAL][1], "bne") == 0){
            //branch_not_equal_to(INSTRUCTION_MEMORY_GLOBAL[PC_GLOBAL][2], INSTRUCTION_MEMORY_GLOBAL[PC_GLOBAL][3], INSTRUCTION_MEMORY_GLOBAL[PC_GLOBAL][4]);
            PC_GLOBAL++;
        }
        else if(strcmp(INSTRUCTION_MEMORY_GLOBAL[PC_GLOBAL][1], "jal") == 0){
            PC_GLOBAL++;
        }
        else if(strcmp(INSTRUCTION_MEMORY_GLOBAL[PC_GLOBAL][1], "jr") == 0){
            PC_GLOBAL++;
        } 
        else if(strcmp(INSTRUCTION_MEMORY_GLOBAL[PC_GLOBAL][1], "j") == 0){
            PC_GLOBAL++;
        }
        else if(strcmp(INSTRUCTION_MEMORY_GLOBAL[PC_GLOBAL][1], "mult") == 0){
            PC_GLOBAL++;
        }
        else{
            printf("\n I MISSED THIS INSTRUCTION: %s", INSTRUCTION_MEMORY_GLOBAL[PC_GLOBAL][1]);
            PC_GLOBAL++;
        }
    }
}

int main(){
    fetch();
    control_logic();
    return 0;
}