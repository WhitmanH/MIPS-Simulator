#include "memory.h"



int read_data_from_memory(int memory_index) {
    return DATA_MEMORY_GLOBAL[memory_index];
}


void write_data_to_memory(int memory_address, int data) {
    DATA_MEMORY_GLOBAL[memory_address] = data;
}