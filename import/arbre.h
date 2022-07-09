#include <stdio.h>
#include <stdlib.h>

struct arbre
{
    int ele;
    struct arbre * sag;
    struct arbre * sad;
}

struct arbre * init_arbre()
{
    struct arbre * creation = (struct arbre *)malloc(struct arbre);
    creation->ele = NULL;
    creation->sag = NULL;
    creation->sad = NULL;
}

struct arbre * init_val(int val)
{
    struct arbre * creation = (struct arbre *)malloc(struct arbre);
    creation->ele = val;
    creation->sag = NULL;
    creation->sad = NULL;
}

