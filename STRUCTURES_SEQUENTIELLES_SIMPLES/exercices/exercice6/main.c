#include <stdio.h>
#include <stdlib.h>
#include "../import/liste.h"


//renverse la liste (*tete) et retourne la nouvelle tete (version iterative)
l_int * renverse_liste_iter(l_int * tete);
//renverse la liste (*tete) et retourne la nouvelle tete (version recucursive)
l_int * renverse_liste_recu(l_int * tete,l_int * prec);

/*test des fonctions*/
void test1();//l_int * renverse_liste_iter(l_int * tete);
void test2();//l_int * renverse_liste_recu(l_int * tete,l_int * prec, l_int * apres);

int main()
{
    test1();
    test2();

//    printf("Hello world!\n");
    return 0;
}

void test1()
{
    l_int * tete = init_lint(12);
    int elements[] = {78,68,95,18,38,65,11,24,52};

    printf("\ntest1 : \n");
    entre_ele(tete,elements,9,file);
    affiche_liste(tete);
    tete = renverse_liste_iter(tete);
    printf("\n\n retournement de la liste et nouvelle disposition : \n");
    affiche_liste(tete);
}

void test2()
{
    l_int * tete = init_lint(12);
    int elements[] = {78,68,95,18,38,65,11,24,52};

    printf("\ntest2 : \n");
    entre_ele(tete,elements,9,file);
    affiche_liste(tete);
    tete = renverse_liste_recu(tete,NULL);
    printf("\n\n retournement de la liste et nouvelle disposition : \n");
    affiche_liste(tete);
}


l_int * renverse_liste_recu(l_int * tete,l_int * prec)
{
    if(tete == NULL)
        return tete;
    if(tete->suiv == NULL)
    {
        tete->suiv = prec;
        return tete;
    }

    l_int * conserve = tete->suiv;
    tete->suiv = prec;
    return renverse_liste_recu(conserve,tete);
}

l_int * renverse_liste_iter(l_int * tete)
{
    if(tete == NULL)
        return tete;
    if(tete->suiv == NULL)
        return tete;
    else
    {
        l_int * prec = NULL;
        l_int * suivant = tete->suiv;
        l_int * parc = tete;

        while((parc->suiv) != NULL)
        {
            parc->suiv = prec;
            prec = parc;
            parc = suivant;
            suivant = parc->suiv;
        }

        parc->suiv = prec;

        return parc;

    }
}


