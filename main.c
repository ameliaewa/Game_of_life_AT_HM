#include <stdio.h>
#include <stdlib.h>
#include "Field.h"
#include "game.h"
#include "txtio.h"

int main(int argc, char** argv) {

    Field* field = argc > 1 ? init_from_txt(argv[1]) : NULL;

    if (field == NULL){
        fprintf(stderr, "NIEPRAWIDLOWA SCIEZKA LUB BRAK SCIEZKI DO PLIKU!!!\n");
        return 1;
    }

    int n = argc > 2 ? atoi(argv[2]) : 0;

    if (n == 0){
        fprintf(stderr, "NALEZY PODAC LICZBE GENERACJI DO WYKONANIA!!!!\n");
        dealloc_field(field);
        return 2;
    }

    while (n--)
    {
        next_gen(field);
        // dla kazdej generacji generowanie obrazka
    }

    FILE *file = argc > 3 ? fopen(argv[3], "w") : fopen("last_gen.txt", "w");
    fprintf(file, "%d %d\n", field->height, field->width);
    for (int i=0; i < field->height; i++){
            for(int j = 0; j < field->width; j++)
                fprintf(file, "%d ", field->cells[i][j]);
            fprintf(file, "\n");
    }

    fclose(file);
    dealloc_field(field);
    // na koniec zapis do pliku w formacie pliku wejsciowego
    return 0;
}


