//
// Created by Rui Tu on 11/9/15.
//

#ifndef PROCESSOR_ASSIGNMENT1_EXECUTEHELPERS_H
#define PROCESSOR_ASSIGNMENT1_EXECUTEHELPERS_H


int find_register_index(char* register_name);
int find_register_value(char* register_name);
void exec_add(char* destination_register_name, char* register1_name, char* register2_name);
void exec_addi(char* destination_register_name, char* register1_name, char* register2_name);
void exec_sub(char* destination_register_name, char* register1_name, char* register2_name);
void exec_slt(char* destination_register_name, char* register1_name, char* register2_name);
void exec_sltu(char* destination_register_name, char* register1_name, char* register2_name);
void load_word(char* destination_register_name, char* base_address_register_name, int offset);
void store_word(char* destination_register_name, char* base_address_register_name, int offset);
void branch_equal_to(char* register1_name, char* register2_name, char* label);
void branch_not_equal_to(char* register1_name, char* register2_name, char* label);

#endif //PROCESSOR_ASSIGNMENT1_EXECUTEHELPERS_H