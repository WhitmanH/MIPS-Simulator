#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CPU/CPU.h"
#include "CPU/executeHelpers/executeHelpers.c"
#define MAX_LINE 100
#define MAX_LENGTH 100


int main()
{
    int pc = 1;
    char *inst[][200] = {{"null", "addi", "$t0", "$zero", "99999" }, {"null", "add", "$t1", "$t1", "$t0"}, {"null", "sub", "t1", "t1", "t1"}};

    exec_addi(inst[0][2], inst[0][3], inst[0][4]);
    exec_add (inst[1][2], inst[1][3], inst[1][4]);
    exec_sub (inst[2][2], inst[2][3], inst[2][4]);


    printf("%s's value is %d", register_string_names[8], register_file[8]);


    return 0;
}
