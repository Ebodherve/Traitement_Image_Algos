#include <stdio.h>
#include <stdlib.h>
#include "../import/liste.h"

void concat_li(l_int * liste1, l_int * liste2);


int main()
{
    l_int *tete1 = init_lint(0);
    l_int *tete2 = init_lint(0);
    int vals1[] = {12,23,4,56,12,32,65,85,63,102};
    int vals2[] = {18,45,62,35,95,75,62};

     entre_ele(tete1,vals1,10,0);
     entre_ele(tete2,vals2,7,0);

    //void * a = "fv";

    printf(" liste une \n");
    affiche_liste(tete1);
    printf(" \n");
    printf(" \n liste deux \n");
    affiche_liste(tete2);
    concat_li(tete1,tete2);
    printf(" \n concatenation des deux listes \n");
    affiche_liste(tete1);



    //printf("Hello world!\n");

    return 0;
}

void concat_li(l_int * liste1, l_int * liste2)
{
    l_int * parc = liste1;

    while(parc->suiv != NULL)
        parc = parc->suiv;
    parc->suiv = liste2;
}


