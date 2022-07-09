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

