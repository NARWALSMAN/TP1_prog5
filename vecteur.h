#ifndef __VECTEUR__
#define __VECTEUR__

struct donnees_vecteur {
    int taille;
    double *donnees;
};

typedef struct donnees_vecteur vecteur;

#include "vecteur_operations.h"
#endif
