#include <stdio.h>
#include <stdlib.h>
#include "../ALU.h"

int add_overflow(int a, int b){
    int c = a + b;
    if (a >= 0 && b >= 0 && c < 0)
        return 1;
    if (a < 0 && b < 0 && c >= 0)
        return 1;
    return 0;
}

int sub_overflow(int a, int b){
    int c =  a - b;
    if (a >= 0 && b < 0 && c < 0)
        return 1;
    if (a < 0 && b >= 0 && c>= 0)
        return 1;
    return 0;
}

void set_signal_integer_overflow(int *flag) {
    *flag = OVERFLOW_SIGNAL;
}

void set_signal_zero_out(int *flag) {
    *flag = ZERO_OUT_SIGNAL;
}