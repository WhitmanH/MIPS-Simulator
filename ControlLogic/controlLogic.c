//
// Created by Rui Tu on 11/8/15.
//

#include "controlLogic.h"
#include "../Registers/registers.h"

/* input: a string of regist name */
/* output: the index of that register in register file array */

int find_register_index(char* register_name[]) {
    int index = 0;
    return index;
}

int find_register_value(char* register_name[]) {
    return register_file[find_register_index(register_name)];
}


// R type, read two register and write to one register