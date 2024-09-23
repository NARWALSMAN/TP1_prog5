#include "utils_tests.h"
#include <stdlib.h>

FILE *output;

void init(char *name) {
    static int first = 1;

    if (first) {
        if (name != NULL) {
            output = fopen(name, "w");
            if (output == NULL) {
                fprintf(stderr, "Erreur interne, impossible de créer le fichier de sortie");
                exit(3);
            }
        } else {
            output = stdout;
        }
        first = 0;
    }
}

FILE *ouvre_fichier_entrees(char *m, int argc, char *argv[]) {
    FILE *f;

    if (argc < 2) {
        fprintf(stderr, "Ce programme prend au moins un argument, le fichier de %s\n", m);
        exit(1);
    }

    init(argv[2]);
    f = fopen(argv[1], "r");
    if (f == NULL) {
        fprintf(stderr, "Erreur d'ouverture du fichier de %s %s\n", m, argv[1]);
        exit(2);
    }
    return f;
}

void shutdown(int code) {
    affiche_test("Difference malloc/free : %d\n", malloc_counter - free_counter);
    fclose(output);
    exit(code);
}
