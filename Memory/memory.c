#include "memory.h"



int read_data_from_memory(int memory_index) {
    return Data_Memory[memory_index];
}


void write_data_to_memory(int memory_address, int data) {
    Data_Memory[memory_address] = data;
}