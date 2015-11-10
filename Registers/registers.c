#include <stdio.h>
#include <stdlib.h>
#include "registers.h"
#include "PC.h"
#include "../Memory/memory.h"
#include "../ALU/ALU.h"


/* USE addALU to computer new address!!!!!!!!  */


void write_data_to_reg(int regfile_index, int data){
    register_file[regfile_index] = data;
}

int load_data_from_register(int register_index) {
    return register_file[register_index];
}



