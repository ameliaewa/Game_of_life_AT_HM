#include "Field.h"
#include "game.h"

// Cell state_update(Field* field, const int x, const int y) {
//     // count alive neighbours
//     int alive_neighbours = count_alive_nghbrs(field, x, y);
//     // apply rules
//     return will_i_survive(field, x, y, alive_neighbours);
// }

int count_alive_nghbrs(Field* field, const int x, const int y) {
    // define adjacency type
    const int NGHBRS = 8;
    int shift[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} }; // moore
    // count neighbours
    int ctr = 0;
    for (int i = 0; i < NGHBRS; ++i) {
        int newx = x + shift[i][0];
        int newy = y + shift[i][1];
        // boundry check
        if (newx >= 0 && newx < field->height && newy >= 0 && newy < field->width)
            ctr += (int)field->cells[newx][newy];
    }
    return ctr;
}

Cell will_i_survive(Field* field, const int x, const int y, int alive_neighbours) {
    // if cell is alive
    if (field->cells[x][y] == ALIVE)
        return (alive_neighbours == 2 || alive_neighbours == 3) ? ALIVE : DEAD;
    // if cell is dead
    return (alive_neighbours == 3) ? ALIVE : DEAD;
}

void next_gen(Field* field) {
    // for each cell in the grid
    for (int y = 0; y < field->width; ++y)
        for (int x = 0; x < field->height; ++x)
            // update cell state
            field->tmpCells[x][y] = will_i_survive(field, x, y, count_alive_nghbrs(field, x, y));
    // swap between tmpCells and Cells array
    swap_cells(field);
}