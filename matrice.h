#ifndef __MATRICE__
#define __MATRICE__

typedef struct donnees_matrice {
    int l, c;
    double **donnees;
} matrice;

#include "matrice_operations.h"
#endif
