#include <stdio.h>
#include <stdlib.h>
#include "../import/liste.h"


l_int * perm_cell(l_int * tete,l_int * t,l_int * v);//permute les cellules v et t dans la liste (* tete)
l_int * mettre_cellule_queue(l_int * tete, l_int * cellule);//met la cellule (* cellule) en queue
int voisin(l_int * tete, l_int * c1,l_int * c2);//teste si (*c1) et (* c2) sont voisines



int main()
{
    l_int * tete = init_lint(12);
    int element[] = {45,12,47,15,35,78,24,95,36};
    int id1,id2;



    entre_ele(tete,element,9,pile);
    affiche_liste(tete);
    printf("\n entrer l'indice du premier element : ");
    scanf("%d",&id1);
    printf("\n entrer l'indice du deuxieme element : ");
    scanf("%d",&id2);
    l_int * t = pointeur_cellule(tete,id1);
    l_int * v = pointeur_cellule(tete,id2);
    printf("valeurs correspondandes %d: %d; %d: %d \n",id1,t->ele,id2,v->ele);

   tete = perm_cell(tete,t,v);
    printf("nouvelle disposition : \n");
    affiche_liste(tete);
/**/

//    printf("Hello world!\n");
    return 0;
}

l_int * perm_cell(l_int * tete,l_int * t,l_int * v)
{
    if(t==v)
        return tete;
    else if(est_cellule_liste(tete,t,0) && !(est_cellule_liste(tete,v,0)))//test si t est dans la liste
    {
            return tete;
    }
    else if(est_cellule_liste(tete,v,0) && !(est_cellule_liste(tete,t,0)))
    {
        return tete;
    }
    else if(!(est_cellule_liste(tete,t,0)) && !(est_cellule_liste(tete,v,0)))
    {
        return tete;
    }else
    {
        if(t == tete)
        {
            if(t->suiv == v)
            {
                t->suiv = v->suiv;
                v->suiv = t;
                return v;
            }
            else
            {
                l_int * suiv_tete = t->suiv;
                t->suiv = v->suiv;
                prev_celluce(suiv_tete,v)->suiv = t;
                v->suiv = suiv_tete;
                return v;
            }
        }else if(v==tete)
        {
            if(v->suiv == t)
            {
                v->suiv = t->suiv;
                t->suiv = v;
                return t;
            }
            else
            {
                l_int * suiv_tete = v->suiv;
                v->suiv = t->suiv;
                prev_celluce(suiv_tete,t)->suiv = v;
                t->suiv = suiv_tete;
                return t;
            }
        }else
        {
            if(t->suiv == v)
            {
                t->suiv = v->suiv ;
                prev_celluce(tete,t)->suiv = v;
                v->suiv = t;
                return tete;
            }
            else if(v->suiv == t)
            {
                v->suiv = t->suiv ;
                prev_celluce(tete,v)->suiv = t;
                t->suiv = v;
                return tete;
            }
            else
            {
                l_int * prev_v = prev_celluce(tete,v);
                l_int * suiv_v = v->suiv;
                l_int * prev_t = prev_celluce(tete,t);

                v->suiv = t->suiv;
                prev_t->suiv = v;
                t->suiv = suiv_v;
                prev_v->suiv = t;

                return tete;

            }
        }
    }

}

l_int * mettre_cellule_queue(l_int * tete, l_int * cellule)
{
    if(tete!=NULL)
    {
        l_int * parc = tete;

        while(parc->suiv != NULL)
        {
            parc = parc->suiv;
        }
        parc->suiv = cellule;

        return tete;
    }

    return cellule;
}


int voisin(l_int * tete, l_int * c1, l_int * c2)
{
    if((c1->suiv == c2)||(prev_celluce(tete,c1) == c2))
        return 1;
    return 0;
}
