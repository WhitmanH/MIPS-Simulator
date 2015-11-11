extern char INSTRUCTION_MEMORY_GLOBAL[1000][1000];



extern int DATA_MEMORY_GLOBAL[1000];
extern int DATA_MEMORY_BASE_INDEX_GLOBAL;
int DATA_MEMORY_BASE_INDEX_GLOBAL = 0;
void write_data_to_memory(int memory_address, int data);
int read_data_from_memory(int memory_index);

