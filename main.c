#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CPU/CPU.h"
#include "CPU/executeHelpers/executeHelpers.c"
#define MAX_LINE 100
#define MAX_LENGTH 100


int main()
{

    exec_addi(INSTRUCTION_MEMORY_GLOBAL[0][2], INSTRUCTION_MEMORY_GLOBAL[0][3], INSTRUCTION_MEMORY_GLOBAL[0][4]);
    exec_addi(INSTRUCTION_MEMORY_GLOBAL[1][2], INSTRUCTION_MEMORY_GLOBAL[1][3], INSTRUCTION_MEMORY_GLOBAL[1][4]);

    branch_not_equal_to(INSTRUCTION_MEMORY_GLOBAL[3][2], INSTRUCTION_MEMORY_GLOBAL[3][3], INSTRUCTION_MEMORY_GLOBAL[3][4]);

    return 0;
}
