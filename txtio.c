#include "txtio.h"

Field* init_from_txt(char* file_path) {
    FILE* file = fopen(file_path, "r");
    if (file == NULL)
        return NULL;
    int w, h;
    fscanf(file, "%d%d", &h, &w);
    Field* field = alloc_field(w, h);

    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            fscanf(file, "%d", (int*)&(field->cells[i][j]));
    fclose(file);
    return field;
}