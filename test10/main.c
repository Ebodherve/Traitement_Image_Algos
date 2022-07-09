#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* programme permettant de resoudre une equation */

typedef struct polynome_2nd
{
    float a;
    float b;
    float c;
} polynome_2nd ;

typedef struct couple
{
    float val1;
    float val2;
}couple;


int est_solution_poly(polynome_2nd p1,float val);
float discriminant(polynome_2nd p1);
float puissance(float val, int n);
int est_solvable(polynome_2nd p1);
couple solutions(polynome_2nd p1);
float eval_pol(polynome_2nd p1, float val);


int main()
{
    polynome_2nd p1;
    float val;

    printf("soit a resoudre une equation du second degre de la forme : aX2 + bX + c = 0 \n");
    printf("entrer la valeur de a : ");
    scanf("%f",&(p1.a));
    printf("entrer la valeur de b : ");
    scanf("%f",&(p1.b));
    printf("entrer la valeur de c : ");
    scanf("%f",&(p1.c));
    printf("votre equation est : %fX2 + %fX + %f \n",p1.a,p1.b,p1.c);

    if(est_solvable(p1))
    {
        couple d_solution = solutions(p1);
        printf("votre equation admet pour solution : %f et %f \n",d_solution.val1,d_solution.val2);
    }else
    printf("votre equation n'a pas de solutions \n");

    printf("evaluation du polynome , entrer la valeur de X : ");
    scanf("%f",&val);
    printf("la valeur de retour est : %f", eval_pol(p1,val));


    //printf("Hello world!\n");

    return 0;
}

int est_solution_poly(polynome_2nd p1,float val)
{
    if(eval_pol(p1,val))
        return 0;
    return 1;
}

float puissance(float val, int n)
{
    float ret = 1;
//    int i;

    for(int i = 0; i<n; i++)
        ret *= val;
    return ret;
}

int est_solvable(polynome_2nd p1)
{
    if(discriminant(p1)<0 || p1.a == 0)
        return 0;
    return 1;
}

couple solutions(polynome_2nd p1)
{
    couple d_racine;
    float delta = discriminant(p1);
    d_racine.val1 = ((-p1.b) - sqrt(delta))/(2*(p1.a));
    d_racine.val2 = ((-p1.b) + sqrt(delta))/(2*(p1.a));
    return d_racine;
}

float discriminant(polynome_2nd p1)
{
    return puissance(p1.b,2) - 4*(p1.a)*(p1.c);
}

float eval_pol(polynome_2nd p1, float val)
{
    return (p1.a)*puissance(val,2)+(p1.b)*val+(p1.c);
}

