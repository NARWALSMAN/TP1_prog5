#include "utils_vecteur.h"
#include "utils_tests.h"
#include <stdio.h>
#include <stdlib.h>

int teste_vecteur_dynamique(vecteur v) {
    int i;
    int limite, extra = 10;

    limite = taille_vecteur(v);
    for (i = -extra; i < 0; i++)
        if (acces_vecteur(v, i) != NULL) {
            affiche_test("Erreur, l'accès à un indice négatif %d donne une adresse non nulle\n", i);
            return 0;
        }
    for (i = limite; i < limite + extra; i++)
        if (acces_vecteur(v, i) != NULL)
            *acces_vecteur(v, i) = 42;
        else {
            affiche_test("Erreur, l'accès à l'indice %d donne une adresse nulle\n", i);
            return 0;
        }
    return 1;
}

void teste_validite(vecteur *v, int n) {
    int ok=1;
#ifdef __VECTEUR_DYNAMIQUE__
    if (!est_vecteur_invalide(v[n])) {
        ok = teste_vecteur_dynamique(v[n]);
        if (!ok)
            n++; // pour libérer aussi le vecteur courant
    }
#endif
    if (!ok || est_vecteur_invalide(v[n])) {
        if (ok)
            affiche_test("Erreur d'allocation du vecteur\n");
        for (int i=0; i<n; i++)
            liberer_vecteur(v[i]);
        shutdown(3);
    }
}

void test_lecture_vecteur(vecteur *v, int n, char *message, FILE *f) {
    v[n] = lit_vecteur(f);
    teste_validite(v, n);
    affiche_test("%s :\n", message);
    affiche_vecteur(v[n]);
}

int main(int argc, char *argv[]) {
    vecteur v[3];
    FILE *f;

    f = ouvre_fichier_entrees("vecteurs", argc, argv);
    test_lecture_vecteur(v, 0, "Premier vecteur", f);
    test_lecture_vecteur(v, 1, "Second vecteur", f);
    fclose(f);

    if (taille_vecteur(v[0]) != taille_vecteur(v[1])) {
        affiche_test("Erreur, les vecteurs sont de taille différente\n");
        exit(4);
    }

    v[2] = allouer_vecteur(taille_vecteur(v[0]));
    teste_validite(v, 2);
    for (int i=0; i<taille_vecteur(v[0]); i++)
        *acces_vecteur(v[2], i) = *acces_vecteur(v[0], i) + *acces_vecteur(v[1], i);
    affiche_test("Somme :\n");
    affiche_vecteur(v[2]);

    liberer_vecteur(v[0]);
    liberer_vecteur(v[1]);
    liberer_vecteur(v[2]);
    shutdown(0);
}
