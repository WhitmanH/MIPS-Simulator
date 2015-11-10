#include <stdio.h>
#include <stdlib.h>
#include "PC.h"

/*
 * input: the pc variable pointer
 * */
void goto_next_instruction() {
    pc = pc + 1;
}

void goto_instruction(int instruction_location) {
    pc = pc + instruction_location;
}