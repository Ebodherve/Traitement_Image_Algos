#include <stdio.h>
#include <stdlib.h>
#include "../import/arbre.h"

int hauteur(struct arbre * racine, int taille);
int max(int val1, int val2);
struct arbre * deshordre();


int main()
{
    struct arbre * racine = deshordre();
//    struct arbre * racine = init_arbre();
//    int element[] = {5,2,10,8,12,1};

//    entre_fixe(racine,element,4);
    post_o(racine);

    printf("\n hauteur de l'arbre %d \n",hauteur(racine,0) );

    return 0;
}



int hauteur(struct arbre * racine, int taille)
{
     if(racine == NULL || racine->ele == NULL)
        return 0;
     else if(racine->sag == NULL && racine->sad == NULL)
        return 1 + taille;
     else
        return max(hauteur(racine->sag, taille + 1),hauteur(racine->sad, taille + 1));
}

int max(int val1, int val2)
{
    if(val1 >= val2)
        return val1;
    else
        return val2;
}

struct arbre * deshordre()
{
    struct arbre * creation = init_val(45);
    creation->sag = init_val(58);
    creation->sad = init_val(12);

    struct arbre * parc = creation->sag;
    parc->sag = init_val(55);
    parc->sad = init_val(23);
    parc = parc->sad;
    parc->sag = init_val(50);


    return creation;

}

