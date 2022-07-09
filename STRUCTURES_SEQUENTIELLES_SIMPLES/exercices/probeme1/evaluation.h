#include "construction.h"

/* module pour évaluer le polynôme pour la valeur x, également saisie au clavier */

//calcule du nombre (nombre) a la puissance (exp)
float puissance(float nombre, int exp);
//evaluation d'un monome
float eval_mono_v0(monome polynome, float val);
//evalulation d'un polynome
float eval_poly_v0(monome polynome, float val);




//calcule du nombre (nombre) a la puissance (exp)
float puissance(float nombre, int exp)
{
    if(exp == 0)
        return 1;
    if(nombre == 0)
        return 0;
    if(exp > 0)
    {
        int ret = 1,i;

        for(i=0; i<exp; i++)
            ret *= nombre;
        return ret;
    }
    else
        return (1/puissance(nombre,-1*exp));

}

//evaluation d'un monome
float eval_mono_v0(monome polynome, float val)
{
    if(polynome == NULL)
        return 0;
    return (polynome->coef)*puissance(val,polynome->exp);
}

//evalulation d'un polynome
float eval_poly_v0(monome polynome, float val)
{
    if(polynome == NULL)
        return 0;
    float val_poly = 0;

    while(polynome != NULL)
    {
        val_poly += eval_mono_v0(polynome,val);
        polynome = polynome->suiv;
    }

    return val_poly;
}







