#include <stdio.h>
#include <stdlib.h>

struct arbre
{
    int ele;
    struct arbre * sag;
    struct arbre * sad;
};


struct arbre * init_a();
struct arbre * init_av(int val);
void post_o(struct arbre * racine);
void entre_o(struct arbre * racine, int val);

void entre_fixe(struct arbre * racine, int t[], int n);

int main()
{
    struct arbre * racine = init_a();
    int element[] = {5,10,8,12,2,1};

    entre_fixe(racine, element, 6);
    post_o(racine);

//    printf("Hello world!\n");
    return 0;
}


struct arbre * init_a()
{
    struct arbre * creation = (struct arbre *)malloc(sizeof(struct arbre));
    creation->ele = NULL;
    creation->sag = NULL;
    creation->sad = NULL;

    return creation;
}

struct arbre * init_av(int val)
{
    struct arbre * creation = (struct arbre *)malloc(sizeof(struct arbre));
    creation->ele = val;
    creation->sag = NULL;
    creation->sad = NULL;

    return creation;
}

void post_o(struct arbre * racine)
{
    if(racine!=NULL && racine->ele!=NULL)
    {
        post_o(racine->sag);
        post_o(racine->sad);
        printf(" %d ",racine->ele);
    }
}

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
                parc->sad = init_av(val);
            }else
            {
                entre_o(parc->sad,val);
            }
        }else
        {
            if(parc->sag == NULL)
            {
                parc->sag = init_av(val);
            }else
            {
                entre_o(parc->sag,val);
            }
        }
    }
}

void entre_fixe(struct arbre * racine, int t[], int n)
{
    int i;

    for(i=0; i<n; i++)
    {
        entre_o(racine, t[i]);
    }
}

