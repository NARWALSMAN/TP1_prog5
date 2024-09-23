#ifndef __VECTEUR_DYNAMIQUE__
#define __VECTEUR_DYNAMIQUE__

struct donnees_vecteur {
    int taille, capacite;
    double *donnees;
};

typedef struct donnees_vecteur *vecteur;

#include "vecteur_operations.h"
#endif
