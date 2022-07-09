#include <stdlib.h>
#include <stdlib.h>


//structure d'une liste simplement chainée
typedef struct liste
{
    int ele;
    struct liste * suiv;
}l_int;

//initiation d'une cellule
l_int * init_lint(int val)
{
    l_int * creation = (l_int *)malloc(sizeof(l_int));
    creation->ele = val;
    creation->suiv = NULL;
}


//ajout d'un element en tete
void aj_tete(l_int * tete, int val)
{
    l_int * creation = init_lint(tete->ele);
    creation->suiv = tete->suiv;
    tete->ele = val;
    tete->suiv = creation;
}

//affichage d'une liste
void affiche_liste(l_int * tete)
{
    l_int * parc = tete;

    while(parc !=NULL)
    {
        printf(" %d ",parc->ele);
        parc = parc->suiv;
    }
}

void aj_queue(l_int * tete, int val)
{
    l_int * creation = tete;

    while(creation->suiv != NULL)
    {
        creation = creation->suiv;
    }

    creation->suiv = init_lint(val);
}





