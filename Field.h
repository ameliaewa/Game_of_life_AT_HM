#ifndef _FIELD_H_
#define _FIELD_H_ 

typedef enum Cell {
    DEAD,
    ALIVE,
} Cell;

typedef struct Field {
    unsigned int width;
    unsigned int height;
    Cell** cells;
    Cell** tmpCells;
} Field;

Field* alloc_field(int, int);
void swap_cells(Field*);
void dealloc_field(Field*);
#endif