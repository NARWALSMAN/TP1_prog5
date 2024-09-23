#include <stdlib.h>
#ifdef MALLOC_FAIL_AFTER
static int remaining = MALLOC_FAIL_AFTER;
#endif

int free_counter = 0;
int malloc_counter = 0;

void *my_malloc(size_t size) {
#ifdef MALLOC_FAIL_AFTER
    if (remaining == 0)
        return NULL;
    else {
        remaining--;
    }
#endif
    malloc_counter++;
    return malloc(size);
};

void *my_realloc(void *p, size_t size) {
#ifdef MALLOC_FAIL_AFTER
    return NULL;
#else
    return realloc(p, size);
#endif
}

void my_free(void *ptr) {
    free_counter++;
    free(ptr);
}
