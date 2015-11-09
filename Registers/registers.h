#define REGISTER_NUMBER 32
#define REGISTER_NAME_LENGTH 5

int reg_write;

int register_file[REGISTER_NUMBER] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

char register_numerical_names[REGISTER_NUMBER][REGISTER_NAME_LENGTH] = {"$0", "$1", "$2", "$3", "$4", "$5", "$6", "$7", "$8", "$9"
        , "$10", "$11", "$12", "$13", "$14", "$15", "$16", "$17", "$18", "$19"
        , "$20", "$21", "$22", "$23", "$24", "$25", "$26", "$27", "$28", "$29"
        , "$30", "$31"};

char register_string_names[REGISTER_NUMBER][REGISTER_NAME_LENGTH] = {"$zero", "$at", "$v0", "$v1", "$a0", "$a3", "$t0", "$t1", "$t2"
        , "$t3", "$t4", "$t5", "$t6", "$t7", "$t8", "$t9", "$s0", "$s1", "$s2", "$s3"
        , "$s4", "$s5", "$s6", "$s7", "$s8", "$k0", "$k1", "$gp", "$sp", "$f0"
        , "$f12", "$f13"};

