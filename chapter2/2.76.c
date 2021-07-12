#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>

const int w = sizeof(int) << 3;

void *my_calloc(size_t nmemb, size_t size) {
    size_t total_size = nmemb * size;
    void *ptr = NULL;
    if (nmemb && size && total_size / nmemb == size) {
        ptr = malloc(total_size);
    }
    if (ptr != NULL) {
        memset(ptr, 0, total_size);
    }
    return ptr;
}

int main() {
    void* p = my_calloc(0x1234, 5);
    assert(p != NULL);
    free(p);
    p = my_calloc(0, 5);
    assert(p == NULL);
    free(p);
    p = my_calloc(SIZE_MAX, 2);
    assert(p == NULL);
    free(p);
    printf("OK\n");
    return 0;
}
