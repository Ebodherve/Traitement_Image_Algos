#include <stdio.h>
#include <stdlib.h>
#include "../import/arbre.h"

int est_eq(struct arbre * racine);
int compte_gen(struct arbre * racine, int taille);
int absolute(int nombre);

int main()
{
    int elements[] = {12,23,8,4,20,25,30,56,57};
    struct arbre * racine = init_arbre();

    entre_fixe(racine,elements,9);

    if(est_eq(racine))
        printf(" Est equilibre ");
    else
        printf(" n'est pas equilibre ");

//    printf("Hello world!\n")
    return 0;
}

int est_eq(struct arbre * racine)
{
    if(racine == NULL)
    {
        return 1;
    }
    else if(racine->sad==NULL && racine->sag==NULL)
    {
        return 1;
    }
    else if(absolute(compte_gen(racine->sad,0)- compte_gen(racine->sag,0)) > 1 )
    {
        return 0;
    }
    else
    {
        return est_eq(racine->sad)*est_eq(racine->sag);
    }
}


int compte_gen(struct arbre * racine, int taille)
{
    if(racine == NULL)
    {
        return 0;
    }else if(racine->sad== NULL && racine->sag== NULL )
    {
        return 1 +taille;
    }
    else
    {
        return max_ab(compte_gen(racine->sad,taille +1), compte_gen(racine->sad,taille+1));
    }
}

int absolute(int nombre)
{
    if(nombre <= 0)
        return nombre*-1;
    return nombre;
}


