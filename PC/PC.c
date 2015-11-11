#include <stdio.h>
#include "PC.h"

/*
 * input: the pc variable pointer
 * */
int PC_GLOBAL;
void goto_next_instruction() {
    PC_GLOBAL = PC_GLOBAL + 1;
    //printf("go to next: the new PC is %d", PC_GLOBAL);
}

void goto_instruction(int instruction_location) {
    PC_GLOBAL = instruction_location;
    //printf("go to instruction: the new PC is %d", PC_GLOBAL);
}

/*
 * return true if there is a next instruction vice versa
 * TODO: implement has_next_instruction()
 * */
int has_next_instruction() {

    return 0;
}