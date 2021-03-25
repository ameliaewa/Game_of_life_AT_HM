#include <stdio.h>
#include <stdlib.h>
#include "Field.h"
#include "game.h"
#include "txtio.h"
#include "pbmgen.h"

int main(int argc, char** argv) {
    Field* field = argc > 1 ? init_from_txt(argv[1]) : NULL;
    if (field == NULL) {
        fprintf(stderr, "Nieprawidłowa ścieżka do pliku!\n");
        return 1;
    }

    int n = argc > 2 ? atoi(argv[2]) : 10;
    if (n <= 0) {
        fprintf(stderr, "Nieprawidłowa liczna iteracji do wykonania!\n");
        dealloc_field(field);
        return 2;
    }

    create_frame(field);
    while (n--) {
        next_gen(field);
        create_frame(field);
    }

    save_to_txt(field, argc > 3 ? argv[3] : "last_gen.txt");

    dealloc_field(field);
    return 0;
}