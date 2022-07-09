#include <stdlib.h>
#include <stdlib.h>
#define pile 1
#define file 0


//structure d'une liste simplement chainée
typedef struct liste
{
    int ele;
    struct liste * suiv;
}l_int;


void affiche_cellule(l_int * cellule);//affichage de l'element dans la cellule (cellule)
void affiche_liste(l_int * tete); // affichage de la liste tete
void aj_tete(l_int * tete, int val); //ajout en tete d'une cellule contenant la valeur val
void aj_queue(l_int * tete, int val); //ajout en queue d'une cellule contenant la valeur val
void liber_cel_tete(l_int ** em_cellule);//libere de la memoire la cellule (* em_cellule) lorsqu'il s'agit de tete
void liber_cel(l_int * cellule);//libere de la memoire la cellule (* cellule)

//entrées des  valeurs du tableau vals dans la liste tete sous forme d'une pile ou d'une file selon  que type = 0/1
void entre_ele(l_int * tete, int vals[], int n, int type);
//supprime la cellule apres (cellule) dans la liste
void supp_cellule_suiv(l_int * cellule);

l_int * init_lint(int val); //intialisation ou ajout d'une cellule dans une liste : cette cellule contient la valeur val
l_int * min_lint(l_int * tete); //retourne la cellule contenant la valeur minimale de la liste
l_int * max_lint(l_int * tete); //retourne la cellule contenant la valeur maximale de la liste

//ajout en tete d'une cellule contenant la valeur val et modification de la l'adresse de la tete (qui est la valeur de retour)
l_int * aj_tete_v0(l_int * tete, int val);
//ajout en queue d'une cellule contenant la valeur val et modification de la l'adresse de la tete (qui est la valeur de retour)
l_int * aj_queue_v0(l_int * tete, int val);
//retoune le pointeur de la cellule de position id
l_int * pointeur_cellule(l_int * tete, int id);
//retoune le pointeur de la cellule de contenu val
l_int * pointeur_cel_val(l_int * tete, int val);
//retourne la cellule avant la cellule (* cellule) dans la liste (*tete)
l_int * prev_celluce(l_int * tete,l_int * cellule);
//retourne la deuxiemme cellule apres (* cellule)
l_int * suiv_suiv(l_int * cellule);
//supprime la cellule (* cellule) de la liste et retourne la *a_tete de la liste
l_int * supp_cellule_liste(l_int ** a_tete, l_int * cellule);
//supprime la cellule (cellule) de la liste (tete)
l_int * supp_cellule_listev0(l_int ** a_tete, l_int * cellule);
//supprime la tete de la liste
l_int * supp_tete(l_int ** tete);


int contient_n_cellule(l_int * tete, int n); //retourne 1 si la liste contient n cellules et 0 si non
int est_cellule_liste(l_int * tete, l_int * cellule, int position);//retourne 0 si cellule n'est pas de la liste et retourne sa position si non
int est_element_cellule(l_int * tete, int ele);//retoune 1 si ele est l'element de la cellule et 0 si non
int est_element_liste(l_int * tete, int val);//retourne 1 val est dans la liste tete et 0 si non
int est_singleton(l_int * tete);//retourne 1 si la liste (tete) est un singleton et 0 sinon
int contenu_cellule(l_int * cellule);//retourne le contenu de la cellule (cellule)
int est_circulaire_liste(l_int * tete);//retourne 1 si la liste est circulaire et 0 si non
int taille_liste(l_int * tete);//retourne la taille de la taille de liste (tete)
int est_vide_liste_pointeur(l_int ** pointeur);//verifie si le pointeur de la liste ou si la liste est vide
int est_vide_liste(l_int * cellule);//verifie si la cellule est vide
int est_pair(int nombre);//retourne 1 si le nombre est pair et 0 si non

//initiation d'une cellule
l_int * init_lint(int val)
{
    l_int * creation = (l_int *)malloc(sizeof(l_int));
    creation->ele = val;
    creation->suiv = NULL;
    return creation;
}


//ajout d'un element en tete
void aj_tete(l_int * tete, int val)
{
    l_int * creation = init_lint(tete->ele);
    creation->suiv = tete->suiv;
    tete->ele = val;
    tete->suiv = creation;
}

//affichage d'une liste
void affiche_liste(l_int * tete)
{
    l_int * parc = tete;

    affiche_cellule(parc);
    if(parc != NULL)
        parc = parc->suiv;

    while((parc !=NULL) && (parc != tete))
    {
        printf(" %d ",parc->ele);
        parc = parc->suiv;
    }
}

void affiche_cellule(l_int * cellule)
{
    if(cellule == NULL)
        printf("");
    else
        printf(" %d ",cellule->ele);
}

//ajout en queue d'une cellule contenant la valeur val
void aj_queue(l_int * tete, int val)
{
    l_int * creation = tete;

    while(creation->suiv != NULL)
    {
        creation = creation->suiv;
    }

    creation->suiv = init_lint(val);
}


//ajout des n elements de vals dans tete selon que: type = 1 -pile ,type = 0 -file
//la liste devrait etre initialise
void entre_ele(l_int * tete, int vals[], int n, int type)
{
    tete->ele = vals[0];

    if(type) // cas d'une pile type = 1
    {
        for(int i = 1; i<n; i++)
        aj_tete(tete,vals[i]);
    }else    // cas d'une file type = 0
    {
        for(int i = 1; i<n; i++)
        aj_queue(tete,vals[i]);
    }

}

void liber_cel_tete(l_int ** em_cellule)//libere de la memoire la cellule (* em_cellule)
{
    *em_cellule = NULL;
}

void liber_cel(l_int * cellule)//libere de la memoire la cellule (* cellule)
{
    free(cellule);
}

//supprime la cellule apres (cellule) dans la liste
void supp_cellule_suiv(l_int * cellule)
{
    if(cellule != NULL)
    {
        l_int * conserve = suiv_suiv(cellule);
        liber_cel(cellule->suiv);
        cellule->suiv = conserve;
    }
}

//ajout en tete d'une cellule contenant la valeur val et modification de la l'adresse de la tete (qui est la valeur de retour)
l_int * aj_tete_v0(l_int * tete, int val)
{
    l_int * creation = (init_lint(val));
    creation->suiv = tete;
    return creation;
}
//ajout en queue d'une cellule contenant la valeur val et modification de la l'adresse de la tete (qui est la valeur de retour)
l_int * aj_queue_v0(l_int * tete, int val)
{

    if(tete == NULL)
    {
        l_int * creation = init_lint(val);
        return creation;
    }else
    {
        aj_queue(tete,val);
        return tete;
        }
}

//retourne 1 si la liste contient n cellules et 0 si non
int contient_n_cellule(l_int * tete,int n)
{
    int cpt = 0;


    if(n<=0)
        return 1;
    else
    {
        l_int * parc = tete;
        while((parc!=NULL)&&(cpt!=n))
        {
            parc = parc->suiv;
            cpt++;
        }
        if(cpt == n)
            return 1;
        else
            return 0;
    }
}

int est_vide_liste_pointeur(l_int ** pointeur)//verifie si le pointeur de la liste ou si la liste est vide
{
    if(pointeur == NULL)
        return 1;
    if(* pointeur == NULL)
        return 1;
    return 0;
}

int est_vide_liste(l_int * cellule)//verifie si la cellule est vide
{
    if(cellule == NULL)
        return 1;
    return 0;
}

int est_pair(int nombre)//retourne 1 si le nombre est pair et 0 si non
{
    if(nombre % 2 == 0)
        return 1;
    return 0;
}

l_int * pointeur_cellule(l_int * tete, int id)
{
    if(id <= 0)
    {
        return tete;
    }
    else
    {
        l_int * parc = tete;
        int cpt = 1;
        while((cpt != id)&&(parc!=NULL))
        {
            parc = parc->suiv;
            cpt++;
        }

        return parc;

    }
}

//retoune le pointeur de la cellule de contenu val
l_int * pointeur_cel_val(l_int * tete, int val)
{
    l_int * parc = tete;

    while(parc != NULL)
    {
        if(contenu_cellule(parc) == val)
            return parc;
        parc = parc->suiv;
    }
    return parc;
}

l_int * suiv_suiv(l_int * cellule) //retourne la liste de la deuxieme liste
{
    l_int * suiv = cellule;

    if(suiv == NULL)
        return NULL ;
    else if(suiv->suiv == NULL)
        return NULL ;
    else
    {
        suiv = suiv->suiv;
        return suiv->suiv;
    }

}


l_int * prev_celluce(l_int * tete,l_int * cellule)//retourne la cellule avant la cellule (* cellule) dans la liste (*tete)
{
    if(tete == NULL)
        return NULL;
    else if(tete == cellule)
        return NULL;
    else
    {
        l_int * parc = tete;
        while((parc->suiv!=cellule)&&(parc->suiv!=NULL))
            parc = parc->suiv;
        if(parc->suiv == cellule)
            return parc;
        return NULL;
    }
}

l_int * supp_cellule_liste(l_int ** a_tete, l_int * cellule)//supprime la cellule (* cellule) de la liste et retourne la tete de la liste
{
    if(a_tete == NULL)
        return NULL;

    l_int * tete = * a_tete ;
    l_int * conserve = NULL ;

    if(tete == NULL || cellule == NULL)
        return tete;
    else if(tete == cellule)
    {
        if(tete->suiv == NULL)
            return NULL;

        l_int * conteneur = tete->suiv;
        * a_tete = NULL;
        return conteneur;
    }
    else
    {
        l_int * cellule_avant = prev_celluce(tete,cellule);
        supp_cellule_suiv(cellule_avant);

        return tete;
    }


}

//supprime la cellule (cellule) de la liste (tete)
l_int * supp_cellule_listev0(l_int ** a_tete, l_int * cellule)
{

    if(a_tete == NULL || * a_tete == NULL || cellule == NULL)
        return NULL;

    l_int * parc = * a_tete;
    l_int * tete = * a_tete;
    l_int * ret = tete->suiv;
    if(tete == cellule)
    {
        * a_tete = NULL;
        return ret;
    }

    while(parc != NULL)
    {
        if(parc->suiv == cellule)
        {
            ret = suiv_suiv(parc);
            parc->suiv = NULL;
            parc->suiv = ret;
            return tete;
        }

        parc = parc->suiv;
    }
    return tete;
}

//supprime la tete de la liste
l_int * supp_tete(l_int ** tete)
{
    if(tete == NULL)
        return NULL;
    l_int * ret = * tete;
    ret = ret->suiv;
    liber_cel_tete(tete);
    return ret;

}

int est_cellule_liste(l_int * tete, l_int * cellule, int position)
{
    if(tete == NULL)
        return 0;
    else if(tete == cellule)
        return 1+position;
    else
        return 0 + est_cellule_liste(tete->suiv, cellule, position+1);
}

int est_element_cellule(l_int * tete, int ele)//retoune 1 si ele est l'element de la cellule et 0 si non
{
    if(tete == NULL)
        return 0;
    else if(tete->ele == ele)
        return 1;
    return 0;
}

int est_element_liste(l_int * tete, int val)
{
    if(tete == NULL)
        return 0;
    else
    {
        l_int * parc = tete;

        while(parc != NULL)
        {
            if(est_element_cellule(parc,val))
                return 1;
            else
                parc = parc->suiv;
        }
        return 0;
    }
}

int contenu_cellule(l_int * cellule)
{
    if(cellule == NULL)
        return 0;
    return cellule->ele;
}

int est_circulaire_liste(l_int * tete)
{
    if(tete == NULL)
        return 0;

    l_int * parc = tete->suiv;
    while(parc != NULL)
    {
        if(parc == tete)
            return 1;

        parc = parc->suiv;
    }

    return 0;

}
//retourne la taille de la taille de liste (tete)s
int taille_liste(l_int * tete)
{
    l_int * parc = tete;
    int taille = 0;
    if(est_singleton(tete))
        return taille;
    while(parc != NULL)
    {
        parc = parc->suiv;
        taille += 1;
    }
    return taille;


}

//retourne 1 si la liste (tete) est un singleton et 0 sinon
int est_singleton(l_int * tete)
{
    if(tete == NULL)
        return 1;
    if(tete->suiv == NULL)
        return 1;
    return 0;
}

l_int * min_lint(l_int * tete) //retourne la cellule contenant la valeur minimale de la liste
{

    l_int * parc = tete;
    l_int * min = tete;

    while(parc->suiv != NULL)
    {
        parc = parc->suiv;
        if(contenu_cellule(parc) < contenu_cellule(min))
            min = parc;
    }
    return min;
}

l_int * max_lint(l_int * tete) //retourne la cellule contenant la valeur maximale de la liste
{
    l_int * parc = tete;
    l_int * max = tete;

    while(parc->suiv != NULL)
    {
        parc = parc->suiv;
        if(contenu_cellule(parc) > contenu_cellule(max))
            max = parc;
    }
    return max;
}

