#include <stdio.h>
#include <stdlib.h>
#include "../import/liste.h"

//supprime une cellule sur deux en comencant par la tete
l_int * supp_cel_1_2_list(l_int ** a_tete);
//supprime les cellules contenant contenant les elements impairs
l_int * supp_cel_impair_list(l_int ** a_tete);
//supprime les cellules contenant contenant les elements pairs
l_int * supp_cel_pair_list(l_int ** a_tete);
//supprime les cellules contenant contenant les elements superieurs un seuil donnée
l_int * supp_cel_gand_seuil(l_int ** a_tete, int seuil);
//supprime les cellules contenant contenant les elements inferieurs un seuil donnée
l_int * supp_cel_petit_seuil(l_int ** a_tete,int seuil);

/* test des cinq fonctions */

void test1();//l_nt * supp_cel_1_2_list(l_int ** a_tete);
void test2();//l_nt * supp_cel_impair_list(l_int ** a_tete);
void test3();//l_nt * supp_cel_pair_list(l_int ** a_tete);
void test4();//l_int * supp_cel_gand_seuil(l_int ** a_tete);
void test5();//l_int * supp_cel_petit_seuil(l_int ** a_tete);

int main()
{
//    test1();
//    test2();
//    test3();
//    test4();
    test5();

//    printf("Hello world!\n");
    return 0;
}



void test1()//l_nt * supp_cel_1_2_list(l_int ** a_tete);
{
    l_int * tete = init_lint(12);
    int elements[] = {45,89,45,36,98,12,35,65,28,49};

    entre_ele(tete,elements,10,file);
    affiche_liste(tete);
    tete = supp_cel_1_2_list(&tete);
    printf("\n affichage de la liste apres la suppresion d'un element sur deux\n");
    affiche_liste(tete);
}

void test2()//l_nt * supp_cel_impair_list(l_int ** a_tete);
{
    l_int * tete = init_lint(12);
    int elements[] = {40,89,45,36,98,12,35,65,28,49};

    entre_ele(tete,elements,10,file);
    affiche_liste(tete);
    tete = supp_cel_impair_list(&tete);
    printf("\n affichage de la liste apres la suppresion des elements impairs\n");
    affiche_liste(tete);
}

void test3()//l_nt * supp_cel_pair_list(l_int ** a_tete);
{
    l_int * tete = init_lint(12);
    int elements[] = {45,89,45,36,98,12,35,65,28,49};

    entre_ele(tete,elements,10,file);
    affiche_liste(tete);
    tete = supp_cel_pair_list(&tete);
    printf("\n affichage de la liste apres la suppresion des elements pairs\n");
    affiche_liste(tete);
}

void test4()//l_int * supp_cel_gand_seuil(l_int ** a_tete);
{
    l_int * tete = init_lint(12);
    int elements[] = {45,89,45,36,98,12,35,65,28,49},seuil;

    entre_ele(tete,elements,10,file);
    affiche_liste(tete);
    printf("\n ecrire le seuil superieur : ");
    scanf("%d",&seuil);
    tete = supp_cel_gand_seuil(&tete,seuil);
    printf("affichage de la liste apres la suppresion des elements superieurs a %d \n", seuil);
    affiche_liste(tete);
}

void test5()//l_int * supp_cel_petit_seuil(l_int ** a_tete);
{
        l_int * tete = init_lint(12);
    int elements[] = {45,89,45,36,98,12,35,65,28,49},seuil;

    entre_ele(tete,elements,10,file);
    affiche_liste(tete);
    printf("\n ecrire le seuil inferieur : ");
    scanf("%d",&seuil);
    tete = supp_cel_petit_seuil(&tete,seuil);
    printf("affichage de la liste apres la suppresion des elements inferieurs a %d \n", seuil);
    affiche_liste(tete);
}

//supprime une cellule sur deux en comencant par la tete
l_int * supp_cel_1_2_list(l_int ** a_tete)
{
    if(a_tete == NULL || * a_tete == NULL)
        return NULL;
    l_int * parc = * a_tete;
    l_int * conserve = parc->suiv;
    * a_tete = NULL;
    parc = conserve;
    l_int * ret = parc;

    while(parc != NULL)
    {
        if(parc->suiv != NULL)
        {
            conserve = suiv_suiv(parc);
            parc->suiv = NULL;
            parc->suiv = conserve;
        }
        parc = parc->suiv;
    }
    return ret;
}

//supprime les cellules contenant contenant les elements impairs
l_int * supp_cel_impair_list(l_int ** a_tete)
{
    if(est_vide_liste_pointeur(a_tete))
        return NULL;

    l_int * parc = * a_tete;
    l_int * tete_pair = NULL;
    l_int * conserve = NULL;

    while(est_vide_liste(tete_pair) && !est_vide_liste(parc))
    {
        if(est_pair(contenu_cellule(parc)))
            tete_pair = parc;
        else if(parc != * a_tete)
        {
            conserve = parc->suiv;
            //parc =NULL;
            liber_cel_tete(&parc);
            parc = conserve;
         }else
        {
            parc = parc->suiv;
            liber_cel_tete(a_tete);
        }
    }

    if(!est_vide_liste(tete_pair))
    {
        parc = tete_pair;

        while(parc != NULL)
        {
            if(est_pair(contenu_cellule(parc->suiv)))
               parc = parc->suiv;
            else
                supp_cellule_suiv(parc);
        }

    }
    return tete_pair;
}

//supprime les cellules contenant contenant les elements pairs
l_int * supp_cel_pair_list(l_int ** a_tete)
{
    if(est_vide_liste_pointeur(a_tete))
        return NULL;

    l_int * parc = * a_tete;
    l_int * tete_impair = NULL;
    l_int * conserve = NULL;

    while(est_vide_liste(tete_impair) && !est_vide_liste(parc))
    {
        if(!est_pair(contenu_cellule(parc)))
            tete_impair = parc;
        else if(parc != * a_tete)
        {
            conserve = parc->suiv;
            //parc =NULL;
            liber_cel_tete(&parc);
            parc = conserve;
         }else
        {
            parc = parc->suiv;
            liber_cel_tete(a_tete);
        }
    }

    if(!est_vide_liste(tete_impair))
    {
        parc = tete_impair;

        while(parc != NULL)
        {
            if(!est_pair(contenu_cellule(parc->suiv)) || est_singleton(parc))
               parc = parc->suiv;
            else
                supp_cellule_suiv(parc);

        }

    }
    return tete_impair;
}

//supprime les cellules contenant contenant les elements superieurs un seuil donnée
l_int * supp_cel_gand_seuil(l_int ** a_tete, int seuil)
{
    if(est_vide_liste_pointeur(a_tete))
        return NULL;

    l_int * parc = * a_tete;
    l_int * tete_petit = NULL;
    l_int * conserve = NULL;

    while(est_vide_liste(tete_petit) && !est_vide_liste(parc))
    {
        if(seuil > contenu_cellule(parc))
            tete_petit = parc;
        else if(parc != * a_tete)
        {
            conserve = parc->suiv;
            liber_cel_tete(&parc);
            parc = conserve;
         }else
        {
            parc = parc->suiv;
            liber_cel_tete(a_tete);
        }
    }

    if(!est_vide_liste(tete_petit))
    {
        parc = tete_petit;

        while(parc != NULL)
        {
            if(seuil > contenu_cellule(parc->suiv) || est_singleton(parc))
               parc = parc->suiv;
            else
            {
                supp_cellule_suiv(parc);

            }

        }
    }

        return tete_petit;
}

//supprime les cellules contenant contenant les elements inferieurs a un seuil donnée
l_int * supp_cel_petit_seuil(l_int ** a_tete, int seuil)
{
    if(est_vide_liste_pointeur(a_tete))
        return NULL;

    l_int * parc = * a_tete;
    l_int * tete_grand = NULL;
    l_int * conserve = NULL;

    while(tete_grand == NULL && !est_vide_liste(parc))
    {
        if(seuil < contenu_cellule(parc))
            tete_grand = parc;
        else if(parc != * a_tete)
        {
            conserve = parc->suiv;
            liber_cel(parc);
            parc = conserve;
         }else
        {
            parc = parc->suiv;
            liber_cel_tete(a_tete);
        }
    }

    if(!est_vide_liste(tete_grand))
    {
        parc = tete_grand;

        while(parc != NULL)
        {
            if(seuil < contenu_cellule(parc->suiv) || est_singleton(parc))
               parc = parc->suiv;
            else
            {
                supp_cellule_suiv(parc);
            }

        }
    }
        return tete_grand;
}

