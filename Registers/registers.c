#include <stdio.h>
#include <stdlib.h>
#include "adderALU.c"
#include <jmorecfg.h>
#include "registers.h"
#include "PC.h"
#include "../Memory/memory.h"
#include "../ALU/ALU.h"


/* USE addALU to computer new address!!!!!!!!  */


void write_data_to_reg(int regfile_index, int data){
    register_file[regfile_index] = data;
}


// input: 16 bits int,
// output: 32 bit int
// sign extend the 16 bit int to 32 bit int
// TODO: implement sign_extend
int32_t sign_extend(int16_t offset) {
    int32_t extended_offset;

    return extended_offset;
}


/* input:int register_index int base_memory_address, int_16 offset*/
/* clear the memory slot and load the word to register file */
// TODO: implement re_load_word
void reg_load_word(int register_index, int32_t base_address, int16_t offset){
    // we will need a unit to sign-extend the 16-bit offset field in the instruction
    // to a 32-bit signed value, and a data memory unit to read from or write to.
}

/* input: int register_index int base_memory_address, int16_t offset*/
/* store the word in the address of the memory */
// TODO: implement re_store_word
void reg_store_word(int register_index, int32_t base_address, int16_t offset) {
    // we will need a unit to sign-extend the 16-bit offset field in the instruction
    // to a 32-bit signed value, and a data memory unit to read from or write to.
}


// beq $t1, $t2, offset
/* input: int register_index1 int reg_index2, int16_t offset, int* pc (pc pointer) */
// TODO: implement branch_equal_to
void branch_equal_to (int reg_index1, int reg_index2, int16_t offset, int* pc) {
    // if the branch condition is true

    /* use sub operation in ALU to determine if two registers have the same value */
    int zero_flag;
    int32_t comparing_result = ALU(ALU_SUB, register_file[reg_index1], register_file[reg_index2], &zero_flag);

    if (zero_flag == 1) {

       jump to the branch location;

    } else {

        go to next instruction;

    }


    // 1. The instruction set architecture specifies that the base for the branch address
    // calculation is the address of the instruction following the branch. Since we compute
    // PC + 4 (the address of the next instruction) in the instruction fetch datapath, it is
    // easy to use this value as the base for computing the branch target address.

    // 2. The architecture also states that the offset field is shifted left 2 bits so that
    // it is a word offset; this shift increases the effective range of the offset field by a
    // factor of 4.
}



