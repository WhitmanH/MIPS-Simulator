#include "../constants.h"
#include <stdio.h>
#include <stdlib.h>

/* ALU operations */
#define ALU_ADD         0x00
#define ALU_SUB         0x01
#define ALU_FUNC        0x02
#define ALU_AND         0x03
#define ALU_OR          0x04
#define ALU_XOR         0x05
#define ALU_LZ          0x06    /* less than zero */
#define ALU_GZ          0x07    /* greather than zero */
#define ALU_LEZ         0x08
#define ALU_GEZ         0x09
#define ALU_DIF         0x0A    /* != */
#define ALU_EQ          0x0B    /* == */
#define ALU_SLT         0x0C    /* set if less than */
#define ALU_SLTU        0x0D
#define ALU_SHIFT16     0x0E
#define ALU_NOP         0x0F
#define ALU_NOR         0x10
#define ALU_ADDU        0x11
#define ALU_SUBU        0x12
#define ALU_MUL         0x13

int32_t alu(int32_t aluin0, int32_t aluin1, uint8_t op, uint32_t *flags);