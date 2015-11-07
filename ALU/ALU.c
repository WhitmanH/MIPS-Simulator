#include <stdio.h>
#include <stdlib.h>
#include "../constants.h"
#include "./ArithmticUnits.h"


int ALU(int *status_in, int opcode, int operand_A, int operand_B, int *integer_result, int *status_out) {
    int (*ALU_operations[8]) (int a, int b);
    ALU_operations[ADD] = ALU_add;
    ALU_operations[SUB] = subtract;
    ALU_operations[AND] = and;
    ALU_operations[ALU_OR] = or;




#define ADD         0x00
#define SUB         0x01
#define FUNC        0x02
#define AND         0x03
#define OR          0x04
#define XOR         0x05
#define LZ          0x06    /* less than zero */
#define GZ          0x07    /* greather than zero */
#define LEZ         0x08
#define GEZ         0x09
#define DIF         0x0A    /* != */
#define EQ          0x0B    /* == */
#define SLT         0x0C    /* set if less than */
#define SLTU        0x0D
#define SHIFT16     0x0E
#define NOP         0x0F
#define NOR         0x10
#define ADDU        0x11
#define SUBU        0x12
#define MUL         0x13

}












