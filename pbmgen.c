#include "pbmgen.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 20

void create_frame(Field* field) {
    static int frameNo = 0;
    static char frameNoStr[BUFF_SIZE] = { 0 };

    // itoa(frameNo, frameNoStr, 10);
    sprintf(frameNoStr, "%d", frameNo);
    strcat(frameNoStr, ".pbm");
    FILE* file = fopen(frameNoStr, "w");
    fprintf(file, "P1\n%d %d\n", field->width, field->height);
    for (int y = 0; y < field->height; ++y) {
        for (int x = 0; x < field->width; ++x)
            fprintf(file, "%d ", field->cells[y][x] == ALIVE ? 1 : 0);
        fputs("\n", file);
    }

    fclose(file);
    frameNo++;
}