#include <stdio.h>
#include <stdlib.h>
#include "../constants.h"

int add_overflow(int32_t a, int32_t b){
    int32_t c = a + b;
    if (a >= 0 && b >= 0 && c < 0)
        return 1;
    if (a < 0 && b < 0 && c >= 0)
        return 1;
    return 0;
}

int sub_overflow(int32_t a, int32_t b){
    int32_t c =  a - b;
    if (a >= 0 && b < 0 && c < 0)
        return 1;
    if (a < 0 && b >= 0 && c>= 0)
        return 1;
    return 0;
}