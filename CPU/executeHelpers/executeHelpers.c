#include <stdio.h>
#include "../../Registers/registers.c"
#include "../../ALU/ALU.c"
#include "../../PC/PC.c"
#include "../../Memory/memory.h"

/* TODO: implement the following instruction
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

    return -1;
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

    write_data_to_register(destination_register_name, ALU(ALU_ADD, register1_value, register2_value, &flag_out));

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

    write_data_to_register(destination_register_name, ALU(ALU_ADD, register1_value, immediate_value, &flag_out));

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

    int data = ALU(ALU_SUB, register1_value, register2_value, &flag_out);
    write_data_to_register(destination_register_name, data);

    if (flag_out == OVERFLOW_SIGNAL) {
        fprintf(stderr, "%d - %d is overflow\n", register1_value, register2_value);
        exit(1);
    }
}

/*
 * TESTED
 * */
void exec_mult(char* destination_register_name, char* register1_name, char* register2_name ) {
    int flag_out;
    int register1_value;
    int register2_value;

    register1_value = find_register_value(register1_name);
    register2_value = find_register_value(register2_name);

    int data = ALU(ALU_MULT, register1_value, register2_value, &flag_out);
    write_data_to_register(destination_register_name, data);

    if (flag_out == OVERFLOW_SIGNAL) {
        fprintf(stderr, "%d - %d is overflow\n", register1_value, register2_value);
        exit(1);
    }
}



/* input:  three register names in string
 * TESTED
=======
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

    write_data_to_register(destination_register_name, ALU(ALU_SLT, register1_value, register2_value, &flag_out));
}

void exec_sltu(char* destination_register_name, char* register1_name, char* register2_name) {
    int flag_out;
    int register1_value;
    int register2_value;

    register1_value = find_register_value(register1_name);
    register2_value = find_register_value(register2_name);

    write_data_to_register(destination_register_name, ALU(ALU_SLTU, register1_value, register2_value, &flag_out));
}


/*============================= memory type, read or store ============================ */

/*
void load_word(char* target_register_name, char* base_address_register_name, int offset){
    int memory_index                    = find_register_value(base_address_register_name);
    int retrieved_value = read_data_from_memory(memory_index + offset/4);
    write_data_to_register(target_register_name, retrieved_value);
    DATA_MEMORY_GLOBAL[memory_index + offset/4] = 0; // set the value slot to zero
}



void store_word(char* target_register_name, char* base_address_register_name, int offset){
    int memory_index = find_register_value(base_address_register_name);
    int retrieved_value = find_register_value(target_register_name);
    write_data_to_memory(memory_index + offset/4, retrieved_value);
}
*/


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

