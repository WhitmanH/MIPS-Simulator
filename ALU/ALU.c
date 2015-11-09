#include <stdio.h>
#include <stdlib.h>
#include "../constants.h"
#include "./ArithmticUnits.h"
#include "ALUhelpers.c"


int32_t ALU(uint8_t opcode, int32_t operand_A, int32_t operand_B, int *status_out) {
    int32_t out;

    if (opcode == ALU_NOP)
        return 0;

    switch(opcode){
        case ALU_ADD:
            if (add_overflow(operand_A, operand_B)) {
                set_signal_integer_overflow(*status_out);
            }
            out = operand_A + operand_B;
            break;
        case ALU_ADDU:
            out = operand_A + operand_B;
            break;
        case ALU_SUB:
            out = operand_A - operand_B;
            break;
        case ALU_SUBU:
            if (sub_overflow(operand_A, operand_B)){
                set_signal_integer_overflow(*status_out);
            }
            out = operand_A - operand_B;
            break;
        case ALU_AND:
            out = operand_A & operand_B;
            break;
        case ALU_OR:
            out = operand_A | operand_B;
            break;
        case ALU_XOR:
            out = (operand_A ^ operand_B);
            break;
        case ALU_LZ:
            out = (operand_A < 0);
            break;
        case ALU_GZ:
            out = (operand_A > 0);
            break;
        case ALU_LEZ:
            out = (operand_A <= 0);
            break;
        case ALU_GEZ:
            out = (operand_A >= 0);
            break;
        case ALU_DIF:
            out = (operand_A != operand_B);
            break;
        case ALU_EQ:
            out = (operand_A == operand_B);
            break;
        case ALU_SLT:
            out = (operand_A < operand_B);
            break;
        case ALU_SLTU:
            out = ((uint32_t) operand_A <  (uint32_t) operand_B);
            break;
        case ALU_SHIFT16:
            out = operand_B << 16;
            break;
        case ALU_NOR:
            out = ~(operand_A | operand_B);
            break;
        case ALU_MUL:
            out = operand_A * operand_B;
            break;
        default:
            fprintf(stderr, "case da alu\n");
            exit(1);
    }

    if (out == 0)
        set_signal_zero_out(*flags);

    return out;
}