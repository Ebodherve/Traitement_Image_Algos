#include <stdio.h>
#include <stdlib.h>
#include "../import/arbre.h"


extern int aboh = 1;

void est_aboh(struct arbre * racine);
struct arbre * deshordre();

int main()
{
 //   struct arbre * racine = deshordre();
    struct arbre * racine = init_arbre();
    int element[] = {5,2,10,8,12,1};

    entre_fixe(racine,element,4);
    post_o(racine);
    est_aboh(racine);

    if(aboh)
        printf("\n cet arbre est un aboh  \n");
    else
        printf("\n cet arbre n'est pas un aboh  \n");

    return 0;
}


void est_aboh(struct arbre * racine)
{struct arbre *test = NULL;
    if(racine != NULL)
    {
        if(racine->sag!=NULL)
        {
            test = racine->sag;
            if(test->ele >= racine->ele)
            {
                aboh = 0;
            }
            est_aboh(racine->sag);
        }
        if(racine->sad!=NULL)
        {
            test = racine->sad;
            if(test->ele < racine->ele)
            {
                aboh = 0;
            }
            est_aboh(racine->sad);
        }
    }
}

struct arbre * deshordre()
{
    struct arbre * creation = init_val(45);
    creation->sag = init_val(58);
    creation->sad = init_val(12);

    struct arbre * parc = creation->sag;
    parc->sag = init_val(55);
    parc->sad = init_val(23);

    return creation;

}
