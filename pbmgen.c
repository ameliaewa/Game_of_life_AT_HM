#include "pbmgen.h"
#include <stdio.h>

#define BUFF_SIZE 20
#define PIXEL_SIZE 10

void create_frame(Field* field) {
    static int frameNo = 0;
    static char buffer[BUFF_SIZE] = { 0 };

    sprintf(buffer, "out/%d.pbm", frameNo);
    FILE* file = fopen(buffer, "w");
    fprintf(file, "P1\n%d %d\n", field->width * PIXEL_SIZE, field->height * PIXEL_SIZE);
    for (int y = 0; y < field->height * PIXEL_SIZE; ++y) {
        for (int x = 0; x < field->width * PIXEL_SIZE; ++x)
            fprintf(file, "%d ", field->cells[y / PIXEL_SIZE][x / PIXEL_SIZE] == ALIVE ? 1 : 0);
        fputs("\n", file);
    }

    fclose(file);
    frameNo++;
}