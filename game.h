#ifndef _GAME_H_
#define _GAME_H_ 

#include "Field.h"

// Cell state_update(Field* field, const int x, const int y);
int count_alive_nghbrs(Field* field, const int x, const int y);
Cell will_i_survive(Field* field, const int x, const int y, int alive_neighbours);
void next_gen(Field* field);

#endif