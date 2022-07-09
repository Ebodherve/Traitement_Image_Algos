#include <stdio.h>
#include <stdlib.h>
#include "../import/liste.h"


typedef struct couple_l
{
    l_int * liste_p;
    l_int * liste_n;
}couple_l;

/* fonction permettant d'extraire la
liste liste_p en liste d'entiers
positif liste_p et en liste d'entiers
negatifs liste_n*/

couple_l sep_po_ne(l_int * liste_p);

int main()
{
    l_int * tete = init_lint(15);
    int elements[] = {12,-65,58,-8,48,-3,56,145,-985,-1};

    entre_ele(tete,elements,10,pile);
    couple_l a_afficher = sep_po_ne(tete);

    printf("Liste principle \n");
    affiche_liste(tete);
    printf("\n\n Lite d'elements positifs \n");
    affiche_liste(a_afficher.liste_p);
    printf("\n\n Lite d'elements negatifs \n");
    affiche_liste(a_afficher.liste_n);

//    printf("Hello world!\n");
    return 0;
 }


couple_l sep_po_ne(l_int * liste_p)
{
 couple_l travail;
 travail.liste_p = NULL;
 travail.liste_n = NULL;

 l_int * parc = liste_p;

 while(parc != NULL)
 {
     if(parc->ele >= 0)
             travail.liste_p = aj_tete_v0(travail.liste_p,parc->ele);
     else
             travail.liste_n = aj_tete_v0(travail.liste_n,parc->ele);
     parc = parc->suiv;
 }

 return travail;

}

