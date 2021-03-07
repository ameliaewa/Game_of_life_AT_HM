#include "Field.h"
#include "game.h"

Cell will_i_survive(Field* field, const int x, const int y) {
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
    if (field->cells[x][y] == ALIVE)
        return (alive_neighbours == 2 || alive_neighbours == 3) ? ALIVE : DEAD;
    return (alive_neighbours == 3) ? ALIVE : DEAD;
}

void next_gen(Field* field) {
    for (int j = 0; j < field->width; ++j)
        for (int i = 0; i < field->height; ++i)
            field->tmpCells[i][j] = will_i_survive(field, i, j);
    swap_cells(field);
   
   
    // UNFINISHED (?)
}