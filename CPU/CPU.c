//
// Created by Rui Tu on 11/9/15.
//

#include "CPU.h"
#include "../PC/PC.h"
int pc;
void fetch() {
    pc = 0;
    // read the misp file and store instructions to the memory property
    // set program counter to the starting point
}


void decode() {
    // pass the instruction header to the control unit to get the correspondent signal

}


void execute() {
    //execute the instruction based on the signal gotten by the control unit

}




void cpu_run() {
    fetch();
    decode();
    execute();
}


