#include "utils_vecteur.h"
#include "utils_tests.h"
#include <stdio.h>
#include <stdlib.h>

double *acces_vecteur_verifie(vecteur v, int i) {
        double *element = acces_vecteur(v, i);
        *element = 0; // Accès préalable pour vérifier que l'adresse est valide
        return element;
}

void affiche_vecteur(vecteur v) {
    int i;

    affiche_test("[ ");
    for (i = 0; i < taille_vecteur(v); i++) {
        affiche_test("%g ", *acces_vecteur(v, i));
    }
    affiche_test("]\n");
}

vecteur lit_vecteur(FILE *f) {
    vecteur v;
    int i, n;
    fscanf(f, " %d", &n);
    v = allouer_vecteur(n);
    if (!est_vecteur_invalide(v))
        for (i = 0; i < n; i++) {
            fscanf(f, " %lg", acces_vecteur_verifie(v, i));
        }
    return v;
}

