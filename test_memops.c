#include "vecteur.h"
#include "utils_vecteur.h"
#include "utils_tests.h"
#include "memory_operations.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    vecteur v1, v2;
    FILE *f;

    f = ouvre_fichier_entrees("vecteurs", argc, argv);
    v1 = lit_vecteur(f);
    v2 = allouer_vecteur(taille_vecteur(v1));
    affiche_vecteur(v1);
    int taille = taille_vecteur(v1);
#ifdef MEMCPY
    my_memcpy(acces_vecteur(v2, 0), acces_vecteur(v1, 0), taille * sizeof(double));
#else
    my_memcpy(acces_vecteur(v2, 0), acces_vecteur(v1, 0), taille * sizeof(double));
    my_memmove(acces_vecteur(v2, 0), acces_vecteur(v2, taille / 4), (taille / 2) * sizeof(double));
    affiche_vecteur(v2);
    my_memcpy(acces_vecteur(v2, 0), acces_vecteur(v1, 0), taille * sizeof(double));
    my_memmove(acces_vecteur(v2, taille / 4), acces_vecteur(v2, 0), (taille / 2) * sizeof(double));
#endif
    affiche_vecteur(v2);
    liberer_vecteur(v1);
    liberer_vecteur(v2);

    affiche_test("Compteur mallocs : %d, compteur frees : %d\n", malloc_counter, free_counter);
    shutdown(0);
}
