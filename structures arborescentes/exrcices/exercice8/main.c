#include <stdio.h>
#include <stdlib.h>
#include "../import/arbre.h"

typedef struct info
{
    int som;
    int nombre;
}info;

int m_nom_pn(struct arbre * racine, int type);
//int m_som_n(struct arbre * racine);

info info_p(struct arbre * racine);
info info_n(struct arbre * racine);

int main()
{
    struct arbre * racine = init_arbre();
    int elements[] = {4,-1,-2,3,-4,6,5,0};

    entre_fixe(racine,elements,8);
//    info info_elements = info_n(racine);

    post_o(racine);
    printf("moyenne des elements positifs : %d, moyenne des elements negatifs : %d ", m_nom_pn(racine,1), m_nom_pn(racine,0));


    //printf("Hello world!\n");
    return 0;
}

/*
int m_som_p(struct arbre * racine, int n_p)
{
    if(racine != NULL)
    {
        return 0;
    }else if(racine->sad == NULL && racine->sag != NULL)
    {
        m_som_n(racine->sag);
    }else if(racine->sag == NULL && racine->sad != NULL)
    {
        m_som_n(racine->sag);
    }else if(racine->sag != NULL && racine->sad != NULL)
    {
        if(racine->ele >= 0)
            return racine->ele;
        return NULL;
    }
    else
    {

    }
}
*/

/*N'est pas encore fini*/



info info_p(struct arbre * racine)
{
    info nv_info;
    if(racine == NULL)
    {
        nv_info.som = 0;
        nv_info.nombre = 0;
        return nv_info;
    }
    else if(racine->sad == NULL && racine->sag==NULL)
    {
        if(racine->ele >= 0)
        {
            nv_info.som = racine->ele;
            nv_info.nombre = 1;
            return nv_info;
        }
        else{
            nv_info.som = 0;
            nv_info.nombre = 0;
            return nv_info;
        }
    }
    else
    {
        if(racine->ele >= 0)
        {
            nv_info.som = racine->ele + info_p(racine->sag).som + info_p(racine->sad).som;
            nv_info.nombre = 1 + info_p(racine->sag).nombre + info_p(racine->sad).nombre;
            return nv_info;
        }
        else{
            nv_info.som = info_p(racine->sag).som + info_p(racine->sad).som;
            nv_info.nombre = info_p(racine->sag).nombre + info_p(racine->sad).nombre;
            return nv_info;
        }
    }
}

info info_n(struct arbre * racine)
{
    info nv_info;
    if(racine == NULL)
    {
        nv_info.som = 0;
        nv_info.nombre = 0;
        return nv_info;
    }
    else if(racine->sad == NULL && racine->sag==NULL)
    {
        if(racine->ele < 0)
        {
            nv_info.som = racine->ele;
            nv_info.nombre = 1;
            return nv_info;
        }
        else{
            nv_info.som = 0;
            nv_info.nombre = 0;
            return nv_info;
        }
    }
    else
    {
        if(racine->ele < 0)
        {
            nv_info.som = racine->ele + info_n(racine->sag).som + info_n(racine->sad).som;
            nv_info.nombre = 1 + info_n(racine->sag).nombre + info_n(racine->sad).nombre;
            return nv_info;
        }
        else{
            nv_info.som = info_n(racine->sag).som + info_n(racine->sad).som;
            nv_info.nombre = info_n(racine->sag).nombre + info_n(racine->sad).nombre;
            return nv_info;
        }
    }
}

int m_nom_pn(struct arbre * racine, int type)
{
    if(type)
    {
        info nv_info = info_p(racine);

        return (nv_info.som)/(nv_info.nombre);
    }else{
        info nv_info = info_n(racine);

        return (nv_info.som)/(nv_info.nombre);
    }
}

