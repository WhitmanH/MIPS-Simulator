#include <stdio.h>
#include <stdlib.h>
#include "PC.h"


/*
 * input: the pc variable pointer
 * */
int PC_GLOBAL = 0;
void goto_next_instruction() {
    PC_GLOBAL = PC_GLOBAL + 1;
}

void goto_instruction(int instruction_location) {
    PC_GLOBAL = instruction_location;
}

/*
 * return true if there is a next instruction vice versa
 * TODO: implement has_next_instruction()
 * */
int has_next_instruction() {

    return 0;
}