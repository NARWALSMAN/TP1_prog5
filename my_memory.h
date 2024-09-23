#include <sys/types.h>

void *my_malloc(size_t size);
void *my_realloc(void *p, size_t size);
void my_free(void *ptr);

extern int malloc_counter;
extern int free_counter;

#define malloc my_malloc
#define realloc my_realloc
#define free my_free
