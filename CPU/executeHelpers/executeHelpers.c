#include "executeHelpers.h"


#include "../../Registers/registers.h"
#include "../../ALU/ALU.h"
#include "../../PC/PC.h"


/*
 * jal
 * j
 * jr
 *
 * How to handle stack and return?
 * */


/* input: a string of label name
 * output: the index of that label in instructions array
 * TODO: implement find_register_index function
 * */
int find_label_index(char* label) {
    int label_index;

    return label_index;
}



/*============= arithmetic type, read two register and write to one register using ALU =========== */\

/* input:  two register names in string
 * do the caculation than write data back to destination register
 * eg: add, $t0, $t1, $t3
 * */
void exec_add(char* destination_register_name, char* register1_name, char* register2_name) {
    int flag_out;
    int register1_value;
    int register2_value;

    register1_value = find_register_value(register1_name);
    register2_value = find_register_value(register2_name);

    write_data_to_reg(destination_register_name, ALU(ALU_ADD, register1_value, register2_value, &flag_out));

    if (flag_out == OVERFLOW_SIGNAL) {
        fprintf(stderr, "%d + %d is overflow\n", register1_value, register2_value);
        exit(1);
    }
}

/* input:  two register names in string
 * do the caculation than write data back to destination register
 * eg: add, $t0, $t1, $t3
 * */
void exec_addi(char* destination_register_name, char* register1_name, char* immediate_name) {
    int flag_out;
    int register1_value;
    int immediate_value;

    register1_value = find_register_value(register1_name);
    immediate_value = get_immediate(immediate_name);

    write_data_to_reg(destination_register_name, ALU(ALU_ADD, register1_value, immediate_value, &flag_out));

    if (flag_out == OVERFLOW_SIGNAL) {
        fprintf(stderr, "%d + %d is overflow\n", register1_value, immediate_value);
        exit(1);
    }
}



/* input:  two register names in string
 * do the caculation than write data back to destination register
 * eg: add, $t0, $t1, $t3
 * */
void exec_sub(char* destination_register_name, char* register1_name, char* register2_name ) {
    int flag_out;
    int register1_value;
    int register2_value;

    register1_value = find_register_value(register1_name);
    register2_value = find_register_value(register2_name);

    write_data_to_reg(destination_register_name, ALU(ALU_SUB, register1_value, register2_value, &flag_out));

    if (flag_out == OVERFLOW_SIGNAL) {
        fprintf(stderr, "%d - %d is overflow\n", register1_value, register2_value);
        exit(1);
    }
}

/* input:  two register names in string
 * do the caculation than write data back to destination register
 * eg: add, $t0, $t1, $t3
 * */
void exec_slt(char* destination_register_name, char* register1_name, char* register2_name) {
    int flag_out;
    int register1_value;
    int register2_value;

    register1_value = find_register_value(register1_name);
    register2_value = find_register_value(register2_name);

    write_data_to_reg(destination_register_name, ALU(ALU_SLT, register1_value, register2_value, &flag_out));
}

void exec_sltu(char* destination_register_name, char* register1_name, char* register2_name) {
    int flag_out;
    int register1_value;
    int register2_value;

    register1_value = find_register_value(register1_name);
    register2_value = find_register_value(register2_name);

    write_data_to_reg(destination_register_name, ALU(ALU_SLTU, register1_value, register2_value, &flag_out));
}



/*============================= memory type, read or store ============================ */

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



/*===================== jump or branch type, go to another address =================== */

/* input: int register_index1 int reg_index2, int16_t offset, int* pc (pc pointer)
 * eg: beq $t1, $t2, offset
 * */
void branch_equal_to(int reg_index1, int reg_index2, char* label) {
    // if the branch condition is true
    /* use sub operation in ALU to determine if two registers have the same value */
    int flag;
    ALU(ALU_SUB, register_file[reg_index1], register_file[reg_index2], &flag);

    if (flag == ZERO_OUT_SIGNAL) {
        int instruction_index;
        instruction_index = find_label_index(label);
        goto_instruction(instruction_index);

    } else {
        goto_next_instruction();
    }
}


void branch_not_equal_to(int reg_index1, int reg_index2, char* label) {
    // if the branch condition is true
    /* use sub operation in ALU to determine if two registers have the same value */
    int flag;
    ALU(ALU_SUB, register_file[reg_index1], register_file[reg_index2], &flag);

    if (flag != ZERO_OUT_SIGNAL) {
        int instruction_index;
        instruction_index = find_label_index(label);
        goto_instruction(instruction_index);
    } else {
        goto_next_instruction();
    }
}
