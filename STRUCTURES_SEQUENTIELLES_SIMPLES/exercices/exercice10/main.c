#include <stdio.h>
#include <stdlib.h>
#include "../import/liste.h"

//coupe la liste (tete) en deux de tel facon à ce que (liste2) soit la deuxieme liste
l_int * coupe_l_2_pointeur(l_int ** a_tete, l_int * liste2);
/*coupe la liste (tete) en deux de tel facon à ce que la deuxieme
 liste soit la liste juste devant la cellule contenant (val)*/
l_int * coupe_l_2_val(l_int ** a_tete, int val);
//coupe la liste (tete) en deux à partir de la cellule de position (position)
l_int * coupe_l_2_position(l_int ** a_tete, int position);
//coupe la liste (tete) en deux à partir de la cellule contenant la valeur minimale
l_int * coupe_l_2_val_min(l_int ** a_tete);
//coupe la liste (tete) en deux de tel facon à ce que (tete) ait une seule cellule
l_int * coupe_l_2_moitier(l_int ** a_tete);
/*test des quatres dernière fonctions */
void test1(); //l_int * coupe_l_2_val(l_int * tete, int val);
void test2(); //l_int * coupe_l_2_position(l_int * tete, int position);
void test3(); //l_int * coupe_l_2_val_min(l_int * tete);
void test4(); //l_int * coupe_l_2_moitier(l_int * tete);

int main()
{
//    test1();
//    test2();
    test3();
//    test4();
//    printf("Hello world!\n");
    return 0;
}


void test1() //l_int * coupe_l_2_val(l_int * tete, int val);
{
    l_int * tete = init_lint(12), * liste2;
    int val,elements[] = {58,35,65,23,14,17,37,86};

    entre_ele(tete,elements,7,pile);
    affiche_liste(tete);
    printf("\n Entrer la valeur a partir de laquelle la liste doit etre couper : ");
    scanf("%d",&val);
    liste2 = coupe_l_2_val(&tete,val);
    printf("Liste - 1 : \n");
    affiche_liste(tete);
    printf("\nListe -  2: \n");
    affiche_liste(liste2);

}

void test2() //l_int * coupe_l_2_position(l_int * tete, int position);
{
    l_int * tete = init_lint(12);
    l_int * liste2 = NULL;
    int position,elements[] = {58,35,65,23,14,17,37,86};

    entre_ele(tete,elements,7,pile);
    affiche_liste(tete);
    printf("\n Entrer la valeur de la position a partir de laquelle la liste doit etre couper : ");
    scanf("%d",&position);
    liste2 = coupe_l_2_position(&tete,position);
    printf("Liste - 1 : \n");
    affiche_liste(tete);
    printf("\nListe -  2: \n");
    affiche_liste(liste2);

}

void test3() //l_int * coupe_l_2_val_min(l_int * tete);
{
    l_int * tete = init_lint(12);
    l_int * liste2 = NULL;
    int position,elements[] = {58,35,65,23,14,17,37,86};

    entre_ele(tete,elements,7,pile);
    affiche_liste(tete);
    printf("\n section de la liste a partir de la valeur minimale\n");
    liste2 = coupe_l_2_val_min(&tete);
    printf("Liste - 1 : \n");
    affiche_liste(tete);
    printf("\nListe -  2: \n");
    affiche_liste(liste2);

}

void test4() //l_int * coupe_l_2_moitier(l_int * tete);
{
    l_int * tete = init_lint(12);
    l_int * liste2;
    int position,elements[] = {58,35,65,23,14,17,37,86};

    entre_ele(tete,elements,7,pile);
    affiche_liste(tete);
    printf("\n section de la liste a partir de la position de moitier ajoute de un\n");
    liste2 = coupe_l_2_moitier(&tete);
    printf("Liste - 1 : \n");
    affiche_liste(tete);
    printf("\nListe -  2: \n");
    affiche_liste(liste2);

}

//coupe la liste (tete) en deux de tel facon à ce que (liste2) soit la deuxieme liste
l_int * coupe_l_2_pointeur(l_int ** a_tete, l_int * liste2)
{
    l_int * tete = * a_tete;

    if(tete == liste2)
    {
        * a_tete = NULL;
        return liste2;
    }else if(est_singleton(tete))
        return NULL;

    l_int * parc = tete;
    while(!(est_singleton(parc))&&(parc->suiv) != liste2)
        parc = parc->suiv;
    parc->suiv = NULL;
    return liste2;

}

/*coupe la liste (tete) en deux de tel facon à ce que la deuxieme
 liste soit la liste juste devant la cellule contenant (val)*/
l_int * coupe_l_2_val(l_int ** a_tete, int val)
{
    l_int * tete = *a_tete;
    if(est_singleton(tete) && !(est_element_cellule(tete,val)))
        return NULL;
    if(est_singleton(tete) || (est_element_cellule(tete,val)))
    {
        l_int * ret = tete;
        *a_tete = NULL;
        return ret;
    }

    l_int * parc = tete;
    while(!(est_singleton(parc))&&!(est_element_cellule(parc->suiv,val)))
        parc = parc->suiv;
    if(parc->suiv == NULL)
    {
        return NULL;
    }
    l_int * ret = parc->suiv;
    parc->suiv = NULL;

    return ret;

}

//coupe la liste (tete) en deux à partir de la cellule de position (position)
l_int * coupe_l_2_position(l_int ** a_tete, int position)
{
    l_int * ret = NULL;
    l_int * tete = * a_tete;
    if(position == 0)
    {
        ret = tete;
        *a_tete = NULL;
        return ret;
    }
    if(position==1)
    {
        ret = tete->suiv;
        tete->suiv = NULL;
        return ret;
    }
    if(taille_liste(tete) > position && position > 1)
    {
        l_int * parc = tete;
        int  cpt;
        for(cpt = 0; cpt < position - 1; cpt++)
            parc = parc->suiv;
        ret = parc->suiv;
        parc->suiv = NULL;
        return ret;

    }
    return NULL;
}

//coupe la liste (tete) en deux à partir de la cellule contenant la valeur minimale
l_int * coupe_l_2_val_min(l_int ** a_tete)
{
    return coupe_l_2_pointeur(a_tete,min_lint(* a_tete));
//    return coupe_l_2_pointeur(a_tete,pointeur_cel_val(* a_tete,14));
}

//coupe la liste (tete) en deux de tel facon à ce que (tete) ait une seule cellule
l_int * coupe_l_2_moitier(l_int ** a_tete)
{
    return coupe_l_2_position(a_tete,(taille_liste(* a_tete)/2) + 1);
}

