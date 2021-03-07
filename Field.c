#include <stdlib.h>
#include "Field.h"

Field* alloc_field(int w, int h) {
    Field* field = (Field*)malloc(sizeof(Field));
    field->width = w;
    field->height = h;
    field->cells = (Cell**)malloc(field->height * sizeof(Cell*));
    field->tmpCells = (Cell**)malloc(field->height * sizeof(Cell*));
    for (int i = 0; i < field->height; ++i) {
        field->cells[i] = (Cell*)malloc(field->width * sizeof(Cell));
        field->tmpCells[i] = (Cell*)malloc(field->width * sizeof(Cell));
    }
    return field;
}

void swap_cells(Field* field) {
    void* tmp = field->cells;
    field->cells = field->tmpCells;
    field->tmpCells = tmp;
}

void dealloc_field(Field* field) {
    for (int i = 0; i < field->height; ++i) {
        free(field->cells[i]);
        free(field->tmpCells[i]);
    }
    free(field->cells);
    free(field->tmpCells);
    free(field);
}