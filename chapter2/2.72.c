#include <stdio.h>
#include <assert.h>
#include <string.h>

void copy_int(int val, void *buf, int maxbytes) {
    if (maxbytes >= (int) sizeof(val)) {
        memcpy(buf, (void *) &val, sizeof(val));
    }
}

int main() {
    int buf = 0;
    copy_int(1, &buf, sizeof(int) - 1);
    assert(buf == 0);
    copy_int(1, &buf, sizeof(int));
    assert(buf == 1);
    printf("OK\n");
    return 0;
}
