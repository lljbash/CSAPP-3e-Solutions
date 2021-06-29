#include <stdio.h>

int is_little_endian() {
    int val = 1;
    return *(unsigned char *) &val;
}

int main() {
    int b = is_little_endian();
    if (b == 1) {
        printf("little endian\n");
    }
    else if (b == 0) {
        printf("big endian\n");
    }
    else {
        printf("unknown endian");
    }
    return 0;
}
