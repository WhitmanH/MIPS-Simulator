#include <stdio.h>
#include <stdlib.h>
#include "ALU.h"
#include "ALUHelpers/ALUhelpers.h"


int ALU(uint8_t opcode, int32_t operand_A, int32_t operand_B, int *flag_out) {
    int out;

    if (opcode == ALU_NOP)
        return 0;

    switch(opcode){
        case ALU_ADD:
            if (add_overflow(operand_A, operand_B)) {
                set_signal_integer_overflow(flag_out);
            }
            out = operand_A + operand_B;
            break;

        case ALU_SUB:
            if (sub_overflow(operand_A, operand_B)) {
                set_signal_integer_overflow(flag_out);
            }
            out = operand_A - operand_B;
            break;
        case ALU_AND:
            out = operand_A & operand_B;
            break;
        case ALU_OR:
            out = operand_A | operand_B;
            break;

        case ALU_NOR:
            out = ~(operand_A | operand_B);
            break;
        case ALU_SLT:
            out = operand_A < operand_B;
            break;

        case ALU_SLTU:
            out = ((uint32_t) operand_A <  (uint32_t) operand_B);
            break;

        default:
            fprintf(stderr, "ALU DONE\n");
            exit(1);
    }

    if (out == 0)
        set_signal_zero_out(flag_out);

    return out;
}