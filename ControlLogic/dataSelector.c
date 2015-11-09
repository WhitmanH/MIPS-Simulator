//
// Created by Rui Tu on 11/8/15.
//

#include "dataSelector.h"


// 1. what value replaces the PC (PC + 4 or the branch destination address);
// the multiplexor is controlled by the gate that “ANDs” together the Zero output
// of the ALU and a control signal that indicates that the instruction is a branch.


// 2.  steer the output of the ALU (in the case of an arithmetic-logical instruction)
// or the output of the data memory (in the case of a load) for writing into the register file.


// 3. determine whether the second ALU input is from the registers (for an arithmetic-logical instruction or a branch)
// or from the offset field of the instruction (for a load or store). The added control lines are straightforward and
// determine the operation performed at the ALU, whether the data memory should read or write, and whether the registers
// should perform a write operation.