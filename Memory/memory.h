char Instruction_Memory[100][1000][100] = {{"null", "addi", "$t0", "$zero", "100" },
                                           {"NULL", "addi", "$t1", "$zero", "100"},
                                           {"for:", "sltu", "$t2", "$t0", "$t1"},
                                           {"null", "beq", "$t0", "$t1", "for" }};
int Data_Memory[1000];

int Instruction_Memory_Length = 4;
int Data_Memory_Base_Index = 0;

void write_data_to_memory(int memory_address, int data);
int read_data_from_memory(int memory_index);

