#include <stdio.h>
#include <limits.h>

int int_shifts_are_arithmetic() {
    int i = INT_MIN;
    return !~(i >> ((sizeof(int) << 3) - 1));
}

int main() {
    printf("%d\n", int_shifts_are_arithmetic());
    return 0;
}
