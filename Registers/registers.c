#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "registers.h"



int register_file[];

void write_data_to_register(char* register_name, int data){
    int register_file_index = find_register_index(register_name);
    register_file[register_file_index] = data;
    register_file[0] = 0;
    //printf("register's been written to name is %s data is %d\n",  register_name, register_file[register_file_index] );

}


/* input: a string of register name
 * output: the index of that register in register file array
 * TODO: implement find_register_index function
 * */

int index_of(char *register_name){
    for(int i = 0; i <= 32; i = i+1){
        if (strcmp(register_string_names[i],register_name) == 0 || strcmp(register_numerical_names[i], register_name) == 0){
            return i;
        }
    }
    return -1;
}

int find_register_index(char* register_name) {
    return index_of(register_name);
}

/* input: a string of register name
 * output: the current value of this register
 * */
int find_register_value(char* register_name) {
    //printf("\nregister name is %s, register index is %d\n", register_name, find_register_index(register_name));
    return register_file[find_register_index(register_name)];
}


long stringToInt(char *number) {
    char *ptr;
    return (strtol(number, &ptr, 10));
}

/* input: a string of immediate name
 * output: value of immediate name
 * */
int get_immediate(char* immediate_name) {
    int immediate_value;
    if ((immediate_name == register_string_names[0]) || (immediate_name == register_numerical_names[0])) {
        immediate_value = 0;
    } else {
        immediate_value = (int) stringToInt(immediate_name);
    }
    return immediate_value;
}

