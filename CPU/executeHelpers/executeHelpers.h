//
// Created by Rui Tu on 11/9/15.
//

#ifndef PROCESSOR_ASSIGNMENT1_EXECUTEHELPERS_H
#define PROCESSOR_ASSIGNMENT1_EXECUTEHELPERS_H

#endif //PROCESSOR_ASSIGNMENT1_EXECUTEHELPERS_H

int find_register_index(char* register_name[]);
int find_register_value(char* register_name[]);
void register_load_word(int register_index, int base_address, int offset);
void register_store_word(int register_index, int base_address, int offset);
void branch_equal_to (int reg_index1, int reg_index2, int offset, int* pc);