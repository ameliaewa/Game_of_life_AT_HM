#include <stdbool.h>

typedef struct Field {
    unsigned int width;
    unsigned int height;
    bool** cells;
} Field;

Field* alloc_field(int, int);