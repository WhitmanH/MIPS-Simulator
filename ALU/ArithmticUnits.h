#include "../constants.h"
#include <stdio.h>
#include <stdlib.h>
#define ADD         0
#define SUB         1
#define FUNC        2
#define AND         3
#define OR          4
#define XOR         5
#define LZ          6    /* less than zero */
#define GZ          7    /* greather than zero */
#define LEZ         8
#define GEZ         9
#define DIF         10    /* != */
#define EQ          11    /* == */
#define SLT         12    /* set if less than */
#define SLTU        0x0D
#define SHIFT16     0x0E
#define NOP         0x0F
#define NOR         0x10
#define ADDU        0x11
#define SUBU        0x12
#define MUL         0x13

int ALU_add(int a, int b) {
    return a + b;
}


int ALU_subtract(int a, int b) {
    return a - b;
}

int ALU_subtract_reverse(int a, int b) {
    return b - a;
}

int ALU_invert(int flag) {
    if (flag == true)
        return false;
    else if (flag == false)
        return true;
    else {
        printf("The invert operation in ALU only accepts 0 or 1\n");
        return -1;
    }
}


int ALU_and(int a, int b) {
    if ((a == true || a == false) && (b == true || b == false)) {
        printf("Two arguments (%d, %d) in and opertion in ALU only accepts 0 or 1\n", a, b);
        return -1;
    }

    if (a == true && b == true) {
        return true;
    } else if (a == false && b == false){
        return false;
    } else if (a != b ) {
        return false;
    }
}


int ALU_or(int a, int b) {
    if ((a == true || a == false) && (b == true || b == false)) {
        printf("Two arguments (%d, %d) in and opertion in ALU only accepts 0 or 1\n", a, b);
        return -1;
    }

    if (a == true && b == true) {
        return true;
    } else if (a == false && b == false){
        return false;
    } else if (a != b ) {
        return true;
    }
}


int ALU_xor(int a, int b) {
    if ((a == true || a == false) && (b == true || b == false)) {
        printf("Two arguments (%d, %d) in and opertion in ALU only accepts 0 or 1\n", a, b);
        return -1;
    }

    if (a == b) {
        return false;
    } else {
        return true;
    }
}