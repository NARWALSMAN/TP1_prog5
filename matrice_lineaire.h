#ifndef __MATRICE_LINEAIRE__
#define __MATRICE_LINEAIRE__

typedef struct donnees_matrice {
    int l, c;
    double *donnees;
} matrice;

#include "matrice_operations.h"
#endif
