#include "executeHelpers.h"


#include "constrolLogic.h"
#include "../../Registers/registers.h"
#include "../../ALU/ALU.h"

/* input: a string of register name
 * output: the index of that register in register file array
 * TODO: implement find_register_index function
 * */
int find_register_index(char* register_name[]) {
    int index = 0;
    return index;
}


/* input: a string of regist name
 * output: the current value of this register
 * */
int find_register_value(char* register_name[]) {
    return register_file[find_register_index(register_name)];
}


/*============= arithmetic type, read two register and write to one register using ALU =========== */







/*============= memory type, read or store =========== */

/* input:int register_index int base_memory_address, int_16 offset
 * clear the memory slot and load the word to register file
 * eg: lw, $t0, 4($s0)
 * TODO: implement re_load_word
 * */
void load_word(int register_index, int base_address, int offset){
    // we will need a unit to sign-extend the 16-bit offset field in the instruction
    // to a 32-bit signed value, and a data memory unit to read from or write to.
}

/* input: int register_index int base_memory_address, int16_t offset*
 * store the word in the address of the memory
 * TODO: implement re_store_word
 * */
void store_word(int register_index, int base_address, int offset) {
    // we will need a unit to sign-extend the 16-bit offset field in the instruction
    // to a 32-bit signed value, and a data memory unit to read from or write to.
}



/*============= jump or branch type, go to another address =========== */


/* input: int register_index1 int reg_index2, int16_t offset, int* pc (pc pointer)
 * eg: beq $t1, $t2, offset
 * TODO: implement branch_equal_to
 * */
void branch_equal_to (int reg_index1, int reg_index2, int offset, int* pc) {
    // if the branch condition is true

    /* use sub operation in ALU to determine if two registers have the same value */
    int zero_flag;
    int comparing_result = ALU(ALU_SUB, register_file[reg_index1], register_file[reg_index2], &zero_flag);

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

