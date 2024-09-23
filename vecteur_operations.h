#ifndef __VECTEUR_OPERATIONS__
#define __VECTEUR_OPERATIONS__

/*
   allouer_vecteur
   description : alloue un vecteur en mémoire
   paramètres : la taille du vecteur (nombre d'éléments)
   valeur de retour : un vecteur de la taille demandée si l'allocation s'est
                      bien passée et un vecteur invalide si une erreur est
                      survenue
   effets de bord : alloue de la mémoire
*/
vecteur allouer_vecteur(int taille);

/*
   liberer_vecteur
   description : libère un vecteur précédemment alloué par alloue_vecteur
   paramètres : le vecteur
   valeur de retour : aucune
   effets de bord : libère de la mémoire
*/
void liberer_vecteur(vecteur v);

/*
   est_vecteur_invalide
   description : retourne 1 si le vecteur donné est invalide
   paramètres : le vecteur
   valeur de retour : 1 si le vecteur est invalide 0 sinon
   effets de bord : aucun
*/
/*
   REMARQUE : la valeur à prendre comme vecteur invalide est a choisir par le
   programmeur qui complète vecteur.c, Il faut choisir une valeur qui ne peut
   pas être prise par un vecteur valide.
*/
int est_vecteur_invalide(vecteur v);

/*
   acces_vecteur
   description : retourne un pointeur vers l'élément d'indice i du vecteur
   paramètres : le vecteur, l'indice de l'élément souhaité
   valeur de retour : un pointeur vers l'élément
   effets de bord : aucun
*/
double *acces_vecteur(vecteur v, int i);

/*
   taille_vecteur
   description : retourne le nombre d'éléments d'un vecteur
   paramètres : le vecteur
   valeur de retour : la taille du vecteur
   effets de bord : aucun
*/
int taille_vecteur(vecteur v);

#endif
