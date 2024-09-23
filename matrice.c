#include "matrice.h"
#include <stdlib.h>

matrice allouer_matrice(int l, int c) {
    matrice m = { l, c, NULL };
    int i;
    m.donnees = malloc(sizeof(double *)*l);
    for (i=0;i<l;i++){
        m.donnees[i] = malloc(sizeof(double)*c);
    }
    return m;
}

void liberer_matrice(matrice m) {
    free(m.donnees);
}

int est_matrice_invalide(matrice m) {
    int resultat = 1;
    if(m.l == 0 && m.c == 0){
        resultat = 0;
    };
    return resultat;
}

double *acces_matrice(matrice m, int i, int j) {
    double *resultat = NULL;
    return resultat;
}

int nb_lignes_matrice(matrice m) {
    int resultat = 0;
    return resultat;
}

int nb_colonnes_matrice(matrice m) {
    int resultat = 0;
    return resultat;
}
