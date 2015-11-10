#include <stdio.h>
#include <stdlib.h>
#include <jmorecfg.h>
#include "PC.h"

/*
 * input: the pc variable pointer
 * */
void goto_next_instruction() {
    PC_GLOABL = PC_GLOABL + 1;
}

void goto_instruction(int instruction_location) {
    PC_GLOABL = instruction_location;
}

/*
 * return true if there is a next instruction vice versa
 * TODO: implement has_next_instruction()
 * */
int has_next_instruction() {

    return 0;
}