#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "registers.h"
#include "../PC/PC.c"
#include "../Memory/memory.c"
#include "../ALU/ALU.c"


void write_data_to_register(char* register_name, int data){
    int register_file_index = find_register_index(register_name);
    register_file[register_file_index] = data;
}


/* input: a string of register name
 * output: the index of that register in register file array
 * TODO: implement find_register_index function
 * */
int find_register_index(char* register_name) {
    int index = 0;

    return index;
}


/* input: a string of register name
 * output: the current value of this register
 * */
int find_register_value(char* register_name) {
    return register_file[find_register_index(register_name)];
}

/* input: a string of immediate name
 * output: value of immediate name
 * */
int get_immediate(char* immediate_name) {
    int immediate_value;
    if (strcmp(immediate_name, "$zero") || strcmp(immediate_name, "$0")) {
        immediate_value = 0;
    } else {
        immediate_value = (int)immediate_name - '0';
    }
    return immediate_value;
}