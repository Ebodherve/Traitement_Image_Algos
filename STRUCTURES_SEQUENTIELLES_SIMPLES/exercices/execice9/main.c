#include <stdio.h>
#include <stdlib.h>
#include "../import/liste.h"


typedef struct couple
{
    int part1;
    int part2;
}couple;

//retourne le produit des nombres positifs part1, et celui des nombres negatifs part2 de la liste tete
couple pos_neg_liste(l_int * tete);

/*test des fonctions */

void test();


int main()
{
    test();
   // printf("Hello world!\n");
    return 0;
}

void test()
{
    l_int * tete = init_lint(45);
    int elements[] = {89,-65,-23,56,14,-12,25,35,-89,-64,17};

    entre_ele(tete,elements,11,file);
    printf("\n test1 : \n");
    affiche_liste(tete);
    couple doublet = pos_neg_liste(tete);
    printf("\n produit des nombres positifs : %d",doublet.part1);
    printf("\n produit des nombres négatifs : %d",doublet.part2);

}

//retourne le produit des nombres positifs part1, et celui des nombres negatifs part2 de la liste tete
couple pos_neg_liste(l_int * tete)
{
    couple doublet = {1,1};
    l_int * parc = tete;

    if(tete == NULL)
    {
        doublet.part1 = 0;
        doublet.part2 = 0;
        return doublet;
    }


    while(parc != NULL)
    {
        if((parc->ele)>=0)
            (doublet.part1) *= (parc->ele);
        else
            (doublet.part2) *= (parc->ele);
        parc = parc->suiv;
    }
    return doublet;

}
