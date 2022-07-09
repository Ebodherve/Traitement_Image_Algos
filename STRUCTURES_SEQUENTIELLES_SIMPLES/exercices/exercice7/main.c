#include <stdio.h>
#include <stdlib.h>
#include "../import/liste.h"

//duplique la liste (* tete)
l_int * duplique_liste(l_int * tete);


/*test des fonctions*/
void test1();

int main()
{
    test1();
//    printf("Hello world!\n");
    return 0;
}

void test1()
{
    l_int * tete = init_lint(89);
    int elements[] = {78,32,65,95,85,15,24,36,18,98};

    entre_ele(tete,elements,10,file);
    printf("\n test1 :\n");
    printf("liste 1 : \n");
    affiche_liste(tete);
    l_int * nv_liste = duplique_liste(tete);
    printf("\n liste dupliquer : \n");
    affiche_liste(nv_liste);

}

l_int * duplique_liste(l_int * tete)
{
    if(tete == NULL)
        return tete;

    l_int * nv_liste = init_lint(tete->ele);
    l_int * parc = nv_liste;
    l_int * parc_tete = tete->suiv;

    while(parc_tete!=NULL)
    {
        parc->suiv = init_lint(parc_tete->ele);

        parc = parc->suiv;
        parc_tete = parc_tete->suiv;
    }

    return nv_liste;
}

