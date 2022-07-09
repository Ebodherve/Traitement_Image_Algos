#include <stdio.h>
#include <stdlib.h>

//structure de representation d'un monome
struct liste
{
    int exp;
    float coef;
    struct liste * suiv;
};

//structure de representation d'un couple
struct couple
{
    int exp;
    float ceof;
};


//structure de representation d'un polynome
struct element_polynome
{
    struct liste * premier;
    struct liste * dernier;
};


typedef struct element_polynome * poly;
typedef struct liste * monome;
typedef struct liste s_monome;
typedef struct couple d_v;





//verifie si le polynome est vide
int est_vide_polynome(monome polynome);
//verifie si le contenu du premier couple est egale au contenu du deuxieme
int est_cp1_egale_cp2(d_v cp1, d_v cp2);
//verfie si l'exposant de monome1 est egale a celui de monome2
int est_exp1_egale_exp2(monome monome1, monome monome2);
//verfie si l'exposant de monome1 est superieur a celui de monome2
int est_exp1_superieur_exp2(monome monome1, monome monome2);


//initialisation d'un polynome ou ajout d'un monome
monome init_polynome(int exp, float coef);
//initialisation d'un polynome ou ajout d'un monome a l'aide d'un couple
monome init_p_couple(d_v contenu);


//retourne le contenu d'un monome
d_v contenu_monome(monome m_extrait);
//creation d'un couple
d_v creation_couple(float coef, int exp);


//affichage d'un couple
void affiche_couple(d_v couple1);
//modification d'un couple
void modif_couple(d_v * n_couple,float coef, int exp);
//allez a la ligne
void ala_ligne();


/*test de certaine fonctions*/
void test1();



//initiation d'un polynome ou ajout d'un monome
monome init_polynome(int exp, float coef)
{
    monome creation = (monome)malloc(sizeof(s_monome));
    creation->coef = coef;
    creation->exp = exp;
    creation->suiv = NULL;

    return creation;
}

//initialisation d'un polynome ou ajout d'un monome a l'aide d'un couple
monome init_p_couple(d_v contenu)
{
    return init_polynome(contenu.exp,contenu.ceof);
}

//verifie si le polynome est vide
int est_vide_polynome(monome polynome)
{
    if(polynome == NULL)
        return 1;
    return 0;
}

//verifie si le contenu du premier couple est egale au contenu du deuxieme
int est_cp1_egale_cp2(d_v cp1, d_v cp2)
{
    if(cp1.ceof != cp2.ceof)
        return 0;
    if(cp1.exp != cp2.exp)
        return 0;
    return 1;
}

//retourne le contenu d'un monome
d_v contenu_monome(monome m_extrait)
{
    if(m_extrait == NULL)
        return creation_couple(0.0,0);

    d_v retour;
    retour.ceof = m_extrait->coef;
    retour.exp = m_extrait->exp;
    return retour;
}

//creation d'un couple
d_v creation_couple(float coef, int exp)
{
    d_v creation;
    creation.ceof = coef;
    creation.exp = exp;
    return creation;
}

//verfie si l'exposant de monome1 est egale a celui de monome2
int est_exp1_egale_exp2(monome monome1, monome monome2)
{
    if(contenu_monome(monome1).exp == contenu_monome(monome2).exp)
        return 1;
    return 0;
}

//verfie si l'exposant de monome1 est superieur a celui de monome2
int est_exp1_superieur_exp2(monome monome1, monome monome2)
{
    if(contenu_monome(monome1).exp > contenu_monome(monome2).exp)
        return 1;
    return 0;
}

//affichage d'un couple
void affiche_couple(d_v couple1)
{
    printf("coefficient : %f; exposant : %d",couple1.ceof,couple1.exp);
}

//modification d'un couple

void modif_couple(d_v * n_couple,float coef, int exp)
{
    n_couple->ceof = coef;
    n_couple->exp = exp;
}


//allez a la ligne
void ala_ligne()
{
    printf("\n");
}

void test1()//void entre_monome(d_v  * cp1)
{
    d_v couple1;
    entre_monome(&couple1);
    affiche_couple(couple1);
}







