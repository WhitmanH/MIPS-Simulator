
char INSTRUCTION_MEMORY_GLOBAL[100][5][15] = {{"null", "addi", "$t0", "$zero", "100" },
                                                {"NULL", "addi", "$t1", "$zero", "100"},
                                                {"for:", "sltu", "$t2", "$t0", "$t1"},
                                                {"null", "beq", "$t0", "$t1", "for" }};
int DATA_MEMORY_GLOBAL[1000];
int INSTRUCTION_MEMORY_GLOBAL_LENGTH;


extern int DATA_MEMORY_BASE_INDEX_GLOBAL;
int DATA_MEMORY_BASE_INDEX_GLOBAL;
void write_data_to_memory(int memory_address, int data);
int read_data_from_memory(int memory_index);