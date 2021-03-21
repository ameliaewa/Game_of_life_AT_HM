#ifndef _TXTIO_H_
#define _TXTIO_H_

#include "Field.h"
#include <stdio.h>

Field* init_from_txt(char* file_path);
void save_to_txt(Field* field, char* file_path);

#endif