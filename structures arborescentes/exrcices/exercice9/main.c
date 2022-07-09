#include <stdio.h>
#include <stdlib.h>
#include "../import/arbre.h"
#include "../import/liste.h"

void arbre_liste(arbre * racine, l_int * tete);


int main()
{
    arbre * racine = init_arbre();
    int elements[] = {45,23,50,46,12,35,58,42,2,5,1,1};
    l_int * tete = init_lint(45);

    entre_fixe(racine,elements,12);
    pre_o(racine);
    arbre_liste(racine,tete);
    printf("\n\n");
    affiche_liste(tete);

//    printf("Hello world!\n");
    return 0;
}

void arbre_liste(arbre * racine, l_int * tete)
{
    arbre * gauche = racine->sag;
    arbre *droite = racine->sad;

    if(gauche != NULL)
    {
        int pere_g = racine->ele, fils_g = gauche->ele;

        if(((pere_g%fils_g)!=0) && ((fils_g%pere_g)!=0))
            {
            aj_tete(tete,fils_g);
            //aj_queue(tete,gauche->ele);
            arbre_liste(gauche,tete);
            }
        else
        {
         arbre_liste(gauche,tete);
        }
    }

    if(droite != NULL)
    {
        int pere_d = racine->ele, fils_d = droite->ele;

        if(((pere_d%fils_d)!=0) && ((fils_d%pere_d)!=0))
        {
         aj_tete(tete,fils_d);
         //aj_queue(tete,droite->ele);
         arbre_liste(droite,tete);
        }
        else
        {
         arbre_liste(droite,tete);
        }
    }

}



