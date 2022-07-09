#include <stdio.h>
#include <stdlib.h>
#include "../import/arbre.h"

void parc_p(struct arbre * racine);

void parc_l(struct arbre * racine);


int main()
{
    struct arbre * racine = init_arbre();
    int elements[] = {5,12,36,4,2,1,69,4,3};

    entre_fixe(racine,elements,9);
    parc_l(racine);
    printf("\n\n\n");
    parc_p(racine);
   // printf("Hello world!\n");
    return 0;
}

void parc_l(struct arbre * racine)
{
    if(racine != NULL)
    {
        parc_l(racine->sag);
        printf(" %d ", racine->ele);
        parc_l(racine->sad);
    }
}

void parc_p(struct arbre * racine)
{
    if(racine != NULL)
    {
        printf(" %d ", racine->ele);
        parc_l(racine->sag);
        parc_l(racine->sad);
    }
}



