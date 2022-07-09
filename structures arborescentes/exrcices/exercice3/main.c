#include <stdio.h>
#include <stdlib.h>
#include "../import/arbre.h"

void recherche(struct arbre * racine, int val);
int trouve = 0;

int main()
{
    int val;
    struct arbre * racine = init_arbre();
    int element[] = {5,2,10,8,12,1};

    entre_fixe(racine, element, 6);
    post_o(racine);

    printf("\n entrer un nombre a chercher dans l'arbre :\n");
    scanf("%d",&val);
    recherche(racine,val);

    if(trouve == 1)

        printf("cet element ce trouve dans l'arbre\n");
    else
        printf("cet element ne ce trouve pas dans l'arbre\n");


    //printf("Hello world!\n");
    return 0;
}



void recherche(struct arbre * racine, int val)
{
    if(racine != NULL && racine->ele != NULL)
    {
        recherche(racine->sag,val);
        recherche(racine->sad,val);

        if(racine->ele == val)
        {
            trouve = 1;
        }
    }
}

