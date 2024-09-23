#include "vecteur.h"
#include <stdlib.h>

vecteur allouer_vecteur(int taille) {
    vecteur v = { 0, NULL };
    v.donnees = malloc(sizeof(double)*taille);
    v.taille = taille;
    return v;
}

void liberer_vecteur(vecteur v) {
    free(v.donnees);
}

int est_vecteur_invalide(vecteur v) {
    int resultat;
    resultat = v.taille == 0;
    return resultat;
}

double *acces_vecteur(vecteur v, int i) {
    double *resultat = NULL;
    resultat = v.donnees + i;
    return resultat;
}

int taille_vecteur(vecteur v) {
    int resultat = v.taille;
    return resultat;
}
