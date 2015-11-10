#include <stdio.h>
#include <stdlib.h>

int add_overflow(int32_t a, int32_t b);
int sub_overflow(int32_t a, int32_t b);
void set_signal_integer_overflow(int *flag);
void set_signal_zero_out(int *flag);