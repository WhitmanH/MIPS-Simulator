#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CPU/CPU.h"
#include "CPU/executeHelpers/executeHelpers.c"
#define MAX_LINE 100
#define MAX_LENGTH 100


int main()
{

    exec_addi(Instruction_Memory[0][2], Instruction_Memory[0][3], Instruction_Memory[0][4]);
    exec_addi(Instruction_Memory[1][2], Instruction_Memory[1][3], Instruction_Memory[1][4]);

    branch_not_equal_to(Instruction_Memory[3][2], Instruction_Memory[3][3], Instruction_Memory[3][4]);


    return 0;
}
