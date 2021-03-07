#ifndef _GAME_H_
#define _GAME_H_ 

#include "Field.h"

#define NEIGHBOURS 8 // zalezy od typu sasiedztwa
int shift[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}; // moore

Cell will_i_survive(Field *field, const int x, const int y);
void next_gen(Field *field);
#endif