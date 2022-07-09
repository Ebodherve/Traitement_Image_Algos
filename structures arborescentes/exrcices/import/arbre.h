#include <stdio.h>
#include <stdlib.h>

typedef struct arbre
{
    int ele;
    struct arbre * sag;
    struct arbre * sad;
} arbre;

int max_ab(int val1, int val2);
int hauteur_ab(struct arbre * racine, int taille);//calcule de la hauteur d'un arbre binaire
struct arbre * init_arbre(); //initialisation
struct arbre * init_val(int val); //initialisation
void post_o(struct arbre * racine); //affichage en post ordre
void entre_o(struct arbre * racine, int val); //insertion pour un ordre horzontale
void pre_o(struct arbre * racine);//affichage d'un ABR en pré-ordre

void entre_fixe(struct arbre * racine, int t[], int n); //insertion d'un nombre fixe d'elements


//initiation d'un arbre binaire de recherche
struct arbre * init_arbre()
{
    struct arbre * creation = (struct arbre *)malloc(sizeof(struct arbre));
    creation->ele = NULL;
    creation->sag = NULL;
    creation->sad = NULL;

    return creation;
}
//initiation d'un arbre binaire de recherche avec valeur 
//(sert principalement a remplir un sous arbre)
struct arbre * init_val(int val)
{
    struct arbre * creation = (struct arbre *)malloc(sizeof(struct arbre));
    creation->ele = val;
    creation->sag = NULL;
    creation->sad = NULL;
}

//affichage d'un ABR en post-ordre
void post_o(struct arbre * racine)
{
    if(racine!=NULL && racine->ele!=NULL)
    {
        post_o(racine->sag);
        post_o(racine->sad);
        printf(" %d ",racine->ele);
    }else if(racine!=NULL && racine->ele==NULL)
    printf(" 0 ");
}

//affichage d'un ABR en pré-ordre
void pre_o(struct arbre * racine)
{
    if(racine!=NULL && racine->ele!=NULL)
    {
        printf(" %d ",racine->ele);
        post_o(racine->sag);
        post_o(racine->sad);
    }else if(racine!=NULL && racine->ele==NULL)
    printf(" 0 ");
}


//entrée en ordre des elements dans un ABR
void entre_o(struct arbre * racine, int val)
{
    struct arbre * parc = racine;

    if(parc->ele == NULL)
    {
        parc->ele = val;
    }
    else
    {
        if(parc->ele <= val)
        {
            if(parc->sad == NULL)
            {
                parc->sad = init_val(val);
            }else
            {
                entre_o(parc->sad,val);
            }
        }else
        {
            if(parc->sag == NULL)
            {
                parc->sag = init_val(val);
            }else
            {
                entre_o(parc->sag,val);
            }
        }
    }
}

//entrée de plusieurs elements dans ABR
//(avec un nombre fixe d'éléments dans le tableau t[])
void entre_fixe(struct arbre * racine, int t[], int n)
{
    int i;

    for(i=0; i<n; i++)
    {
        entre_o(racine, t[i]);
    }
}

//calcule de la hauteur d'un arbre
int hauteur_ab(struct arbre * racine, int taille)
{
     if(racine == NULL || racine->ele == NULL)
        return 0;
     else if(racine->sag == NULL && racine->sad == NULL)
        return 1 + taille;
     else
        return max_ab(hauteur_ab(racine->sag, taille + 1),hauteur_ab(racine->sad, taille + 1));
}

//maximum de deux nombres
int max_ab(int val1, int val2)
{
    if(val1>=val2)
    return val1;

    return val2;
}

