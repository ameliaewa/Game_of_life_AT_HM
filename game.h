#ifndef _GAME_H_
#define _GAME_H_ 

#include "Field.h"

Cell will_i_survive(Field* field, const int x, const int y);
void next_gen(Field* field);

#endif