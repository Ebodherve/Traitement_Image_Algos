#include <stdio.h>
#include <stdlib.h>
#include "../import/liste.h"


int max_ele_iter(l_int * tete);
int max_ele_recu(l_int * tete);
int max_int(int ele1, int ele2);


int main()
{
    l_int *tete = init_lint(0);
    int vals[] = {12,23,4,56,12,32,65,85,63,102};

     entre_ele(tete,vals,10,0);

    //void * a = "fv";

    affiche_liste(tete);
    printf(" \n");
   // printf(" le max de la liste est : %d",max_ele_iter(tete));
    printf(" le max de la liste est : %d",max_ele_recu(tete));


    //printf("Hello world!\n");
        return 0;
}

int max_ele_iter(l_int * tete)
{
    int max_l = tete->ele;
    l_int * parc = tete->suiv;

    while(parc != NULL)
    {
        if((parc->ele) > max_l)
            max_l = parc->ele;

        parc = parc->suiv;
    }

    return max_l;
}

int max_ele_recu(l_int *tete)
{
   if(tete->suiv == NULL)
       return tete->ele;
    else
        return max_int(tete->ele, max_ele_recu(tete->suiv));
}

int max_int(int ele1, int ele2)
{
    if(ele1 > ele2)
        return ele1;
    return ele2;
}

