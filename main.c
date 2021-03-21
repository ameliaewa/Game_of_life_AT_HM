#include <stdio.h>
#include <stdlib.h>
#include "Field.h"
#include "game.h"
#include "txtio.h"
#include "pbmgen.h"

int main(int argc, char** argv) {

    Field* field = argc > 1 ? init_from_txt(argv[1]) : NULL;

    if (field == NULL) {
        fprintf(stderr, "NIEPRAWIDLOWA SCIEZKA LUB BRAK SCIEZKI DO PLIKU!!!\n");
        return 1;
    }

    int n = argc > 2 ? atoi(argv[2]) : 0;

    if (n == 0) {
        fprintf(stderr, "NALEZY PODAC LICZBE GENERACJI DO WYKONANIA!!!\n");
        dealloc_field(field);
        return 2;
    }

    create_frame(field);
    while (n--) {
        next_gen(field);
        // dla kazdej generacji generowanie obrazka
        create_frame(field);
    }

    save_to_txt(field, argc > 3 ? argv[3] : "last_gen.txt");

    dealloc_field(field);
    // na koniec zapis do pliku w formacie pliku wejsciowego
    return 0;
}


