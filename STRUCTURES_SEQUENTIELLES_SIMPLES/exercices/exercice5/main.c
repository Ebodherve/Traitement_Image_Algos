#include <stdio.h>
#include <stdlib.h>
#include "../import/liste.h"

//suppression de toute les occurence de x dans la liste
l_int * supp_tout_occ(l_int * tete, int x);
// suppression des k premieres occurences de x dans la liste
l_int * supp_k_occ(l_int * tete, int x, int k);
// suppression de toutes les occurences de x dans la liste (apres la premiere occurence)
l_int * supp_suiv_occ(l_int * tete, int x);
//suppression chacune des occurences des elements la liste apres ca premiere occurence
l_int * supp_suiv_tout_occ(l_int * tete);


/*test des fonctions*/
void test1();
void test2();
void test3();


int main()
{
//    test1();
    test2();
//    test3();

//    printf("Hello world!\n");
    return 0;
}

void test1()
{
    l_int * tete = init_lint(12);
    int elements[] = {45,56,85,48,46,56,48,56,12,32,98,56},ele_supp;

    entre_ele(tete,elements,12,file);
    affiche_liste(tete);

    printf("\n\n entrer la valeur dont on doit supprimer les occurencesdans la liste : ");
    scanf("%d",&ele_supp);
    tete = supp_tout_occ(tete,ele_supp);
    printf("affichage de la nouvelle liste : \n");
    affiche_liste(tete);
}

void test2()
{
    l_int * tete = init_lint(12);
    int elements[] = {45,56,85,48,46,56,48,56,12,32,98,56},ele_supp,k;

    entre_ele(tete,elements,12,file);
    affiche_liste(tete);

    printf("\n\n entrer la valeur dont on doit supprimer les occurencesdans la liste : ");
    scanf("%d",&ele_supp);
    printf("entrer le nombre des premieres occurences a ne pas supprimer : ");
    scanf("%d",&k);
    tete = supp_k_occ(tete,ele_supp,k);
    printf("affichage de la nouvelle liste : \n");
    affiche_liste(tete);
}

void test3()
{
    l_int * tete = init_lint(12);
    int elements[] = {45,56,85,48,46,56,48,56,85,32,98,56},ele_supp,k;

    entre_ele(tete,elements,12,file);
    affiche_liste(tete);
    tete = supp_suiv_tout_occ(tete);
    printf("nouvelle liste apres suppresion des repetitions d'elements \n");
    affiche_liste(tete);

}

//suppression de toute les occurence de x dans la liste
l_int * supp_tout_occ(l_int * tete, int x)
{
    l_int * n_tete = tete;

    if(tete == NULL)
        return tete;
    else
    {
        l_int * parc = n_tete;

        while((parc != NULL)&&(est_element_cellule(parc,x)))
        {
            n_tete = parc->suiv;
            parc = NULL;
            parc = n_tete;
        }

        while(parc != NULL)
        {
            if(est_element_cellule(parc->suiv,x))
            {
                l_int * conserve = suiv_suiv(parc);
                parc->suiv = NULL;
                parc->suiv = conserve;

            }
            else
                parc = parc->suiv;
        }
        return n_tete;

    }
}

l_int * supp_k_occ(l_int * tete, int x, int k)
{
    int cpt = 0;
    l_int * parc  = tete;
    l_int * conserve  = tete;

    if(k==0)
    {
        return supp_tout_occ(tete,x);

    }

    while(parc != NULL && cpt != k)
    {
        if(est_element_cellule(parc,x))
            cpt += 1;
        conserve = parc;
        parc = parc->suiv;
    }

    if(cpt == k && parc != NULL)
        conserve->suiv = supp_tout_occ(conserve->suiv,x);

    return tete;
}

l_int * supp_suiv_occ(l_int * tete, int x)
{
    return supp_k_occ(tete,x,1);
}

l_int * supp_suiv_tout_occ(l_int * tete)
{

    l_int * n_tete = tete;
    //int i;

    if(n_tete != NULL)
        n_tete = supp_suiv_occ(n_tete,n_tete->ele);
    l_int * parc = n_tete;

    while(parc != NULL)
    {
        if(parc->suiv != NULL)
            parc->suiv = supp_suiv_occ(parc->suiv,contenu_cellule(parc->suiv));
        parc = parc->suiv;
    }
    return n_tete;
}


