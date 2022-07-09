#include <stdio.h>
#include <stdlib.h>
#include "../import/liste.h"

void referme_liste(l_int * tete);

/*test des fonctions*/
void test1();
void mini_test1(l_int * tete);

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
    printf("affichage de la liste : \n");
    affiche_liste(tete);
    mini_test1(tete);
    referme_liste(tete);
    printf("\n affichage de la liste apres fermeture de celle ci : \n");
    affiche_liste(tete);
    mini_test1(tete);

}

void referme_liste(l_int * tete)
{
    if(tete == NULL)
        return NULL;
    l_int * parc = tete;
    while(parc->suiv != NULL)
        parc = parc->suiv;
    parc->suiv = tete;
}

void mini_test1(l_int * tete)
{
    if(est_circulaire_liste(tete))
        printf("\n Cette liste est circulaire\n");
    else
        printf("\n Cette liste n'est pas circulaire\n");
}
