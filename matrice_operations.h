#ifndef __MATRICE_OPERATIONS__
#define __MATRICE_OPERATIONS__

/*
   allouer_matrice
   description : alloue une matrice en mémoire
   paramètres : le nombre de lignes et de colones de la matrice
   valeur de retour : une matrice de la taille demandée si l'allocation s'est
                      bien passée et une matrice invalide si une erreur est
                      survenue
   effets de bord : alloue de la mémoire
*/
matrice allouer_matrice(int l, int c);

/*
   liberer_matrice
   description : libère une matrice précédemment allouée par alloue_matrice
   paramètres : la matrice
   valeur de retour : aucune
   effets de bord : libère de la mémoire
*/
void liberer_matrice(matrice m);

/*
   est_matrice_invalide
   description : retourne 1 si la matrice est invalide
   paramètres : la matrice
   valeur de retour : 1 si la matrice est invalide 0 sinon
   effets de bord : aucun
*/
int est_matrice_invalide(matrice m);

/*
   acces_matrice
   description : retourne un pointeur vers l'élément d'indice (i,j) de la
                 matrice (ligne i, colonne j)
   paramètres : la matrice, les indices de l'élément souhaité
   valeur de retour : un pointeur vers l'élément
   effets de bord : aucun
*/
double *acces_matrice(matrice m, int i, int j);

/*
   nb_lignes_matrice
   description : retourne le nombre de lignes d'une matrice
   paramètres : la matrice
   valeur de retour : le nombre de lignes
   effets de bord : aucun
*/
int nb_lignes_matrice(matrice m);

/*
   nb_colonnes_matrice
   description : retourne le nombre de colonnes d'une matrice
   paramètres : la matrice
   valeur de retour : le nombre de colonnes
   effets de bord : aucun
*/
int nb_colonnes_matrice(matrice m);

#endif
