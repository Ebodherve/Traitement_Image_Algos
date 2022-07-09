#include <stdio.h>
#include <stdlib.h>

typedef struct liste
{
    int ele;
    struct liste *suiv;
} liste;

struct liste * ajout_l(struct liste * tete, int val);
void affiche(struct liste * tete);
struct liste * ajout_q(struct liste * tete, int val);

int main()
{
   // struct liste * parc = NULL;
    struct liste * tete = NULL;
    int i,val;

    /*tete = (struct liste *)malloc(sizeof(struct liste));
    tete->ele = 5;
    tete->suiv = NULL;
    */

    for(i = 0; i<5; i++)
    {
        printf("element %d  ", i+1);
        scanf("%d",&val);
        //tete = ajout_l(tete,val);
        tete = ajout_q(tete,val);
    }

    affiche(tete);

   // printf(" %d ",tete->ele);

    return 0;
}

void affiche(struct liste * tete)
{
    struct liste * parc = tete;

    while(parc != NULL)
    {
        printf(" %d ", parc->ele);
        parc = parc->suiv;
    }
}

struct liste * ajout_l(struct liste * tete, int val)
{
    struct liste * parc = NULL;
    parc = (struct liste *)malloc(sizeof(struct liste));
    parc->ele = val;
    parc->suiv = tete;

    return parc;

}

struct liste * ajout_q(struct liste * tete, int val)
{
    struct liste * parc = tete;
    struct liste * creation = NULL;

    if(tete == NULL)
    {
        creation = (struct liste *)malloc(sizeof(struct liste));
        creation->ele = val;
        creation->suiv = NULL;
        return creation;
    }
    else
    {

    while(parc->suiv != NULL)
    {
        parc = parc->suiv;
    }
    creation = (struct liste *)malloc(sizeof(struct liste));
    creation->ele = val;
    creation->suiv = NULL;
    parc->suiv = creation;
    return tete;
    }



}

