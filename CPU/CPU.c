//
// Created by Rui Tu on 11/9/15.
//

#include "CPU.h"
#include "../PC/PC.h"
int pc;
void fetch() {
    PC_GLOABL = 0;
    // read the misp file and store instructions to the memory property
    // set program counter to the starting point
}


void decode() {
    // pass the instruction header to the control unit to get the correspondent signal
    // find out which instructions to execute
}


void execute() {
    //execute the instructions

}




void cpu_run() {
    while (has_next_instruction()) {
        fetch();
        decode();
        execute();
    }
}


