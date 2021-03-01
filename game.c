#include "Field.h"

#define DEAD 0
#define ALIVE 1

#define NEIGHBOURS 8 // zalezy od typu sasiedztwa
int shift[8][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} }; // moore
// int shift[4][2] = { {-1,0},{0,-1},{0,1},{1,0} }; // neumann

bool will_i_survive(Field* field, const int x, const int y) {
    // count alive neighbours
    int alive_neighbours = 0;
    for (int i = 0; i < NEIGHBOURS; ++i) {
        int newx = x + shift[i][0];
        int newy = y + shift[i][1];
        // boundry check
        if (newx >= 0 && newx < field->height && newy >= 0 && newy < field->width)
            alive_neighbours += (int)field->cells[newx][newy]; // cells[nx]][ny] ? 1 : 0
    }
    // rules
    if (field->cells[x][y] == ALIVE) {
        return (alive_neighbours == 2 || alive_neighbours == 3);
    }
    if (field->cells[x][y] == DEAD) {
        return (alive_neighbours == 3);
    }
}

void swap_fields(Field* a, Field* b) {
    Field* tmp = a;
    a = b;
    b = tmp;
}

void next_gen(Field* field) {
    static Field* tmp = alloc_field(field->width, field->height);
    for (int j = 0; j < field->width; ++j)
        for (int i = 0; i < field->height; ++i)
            tmp[i][j] = will_i_survive(field, i, j);
    swap_fields(tmp, field);
}