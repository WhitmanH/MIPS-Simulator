#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "../PC/PC.h"
#include "../CPU/CPU.h"
#include "../CPU/CPU.c"
#include "../CPU/executeHelpers/executeHelpers.c"
extern int INSTRUCTION_MEMORY_GLOBAL_LENGTH;


void control_logic() {
    char INSTRUCTION_MEMORY_GLOBAL[100][5][15];
    printf("Length of instructions: %d\n", INSTRUCTION_MEMORY_GLOBAL_LENGTH);
    int PC = 0;

    while(PC < INSTRUCTION_MEMORY_GLOBAL_LENGTH -1){
        char *label                =  INSTRUCTION_MEMORY_GLOBAL[PC][0];
        char *instruction_header   =  INSTRUCTION_MEMORY_GLOBAL[PC][1];
        char *destination_register =  INSTRUCTION_MEMORY_GLOBAL[PC][2];
        char *operand_A            =  INSTRUCTION_MEMORY_GLOBAL[PC][3];
        char *operand_B            =  INSTRUCTION_MEMORY_GLOBAL[PC][4];


        if(strcmp(instruction_header, "add") == 0){
            exec_add(destination_register, operand_A, operand_B);
            printf("\ndebug: we are adding registers: %s and %s to register: %s", operand_A, operand_B, destination_register);
            PC++;
        }
        else if(strcmp(instruction_header, "addi") == 0){
            exec_addi(destination_register, operand_A, operand_B);
            PC++;
        }
        else if(strcmp(instruction_header, "sub") == 0){
            exec_sub(destination_register, operand_A, operand_B);
            PC++;
        }
        else if(strcmp(instruction_header, "slt") == 0){
            exec_slt(destination_register, operand_A, operand_B);
            PC++;
        }
        else if(strcmp(instruction_header, "sltu") == 0){
            exec_sltu(destination_register, operand_A, operand_B);
            PC++;
        }
        else if(strcmp(instruction_header, "lw") == 0){
            PC++;
        }
        else if(strcmp(instruction_header, "sw") == 0){
            PC++;
        }
        else if(strcmp(instruction_header, "beq") == 0){
            branch_equal_to(operand_A, operand_B, label);
        }
        else if(strcmp(instruction_header, "bne") == 0){
            branch_not_equal_to(operand_A, operand_B, label);
        }
        else if(strcmp(instruction_header, "jal") == 0) {

        }
        else if(strcmp(instruction_header, "jr") == 0){

        }
        else if(strcmp(instruction_header, "j") == 0){

        }
        else if(strcmp(instruction_header, "mult") == 0){
            PC++;

        }
        else{
            printf("\n I MISSED THIS INSTRUCTION: %s", instruction_header);
        }
        PC++;

    }
    
}

