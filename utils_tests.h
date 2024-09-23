#ifndef __UTILS_TESTS__
#define __UTILS_TESTS__
#include <stdio.h>

extern FILE *output;

#define affiche_test(...) fprintf(output, __VA_ARGS__)

void init(char *filename);
FILE *ouvre_fichier_entrees(char *m, int argc, char *argv[]);
void shutdown(int code);

#endif
