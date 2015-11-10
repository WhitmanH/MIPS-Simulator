#include <stdio.h>
#include <stdlib.h>

/* ALU operations */

/* R type instructions */
#define ALU_ADD         0x01
#define ALU_SUB         0x02
#define ALU_AND         0x03
#define ALU_OR          0x04
#define ALU_SLT         0x05    /* set if less than */
#define ALU_NOR         0x06

int32_t ALU(uint8_t opcode, int32_t operand_A, int32_t operand_B, int *status_out);