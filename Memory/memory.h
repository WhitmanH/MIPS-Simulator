char INSTRUCTION_MEMORY_GLOBAL[100][5][15];
int DATA_MEMORY_GLOBAL[1000];

/*
 * DATA MEMORY GLOBAL SHOULD BE
 * TODO: initialize the data memory array.
 * */
int INSTRUCTION_MEMORY_GLOBAL_LENGTH;

extern int DATA_MEMORY_BASE_INDEX_GLOBAL;
int DATA_MEMORY_BASE_INDEX_GLOBAL;

void write_data_to_memory(int memory_address, int data);
int read_data_from_memory(int memory_index);
void initialize_data_memory();