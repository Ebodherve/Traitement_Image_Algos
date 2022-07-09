#include <stdio.h>
#include <stdlib.h>
#include <math.h>


float suite1_rec(int n);

int main()
{
    int n;

    printf("U0 = 1; Un+1 = rc(1+Un) pour un test U1 = %f U2 = %f\n",sqrt(2),sqrt(1+sqrt(2)));
    printf(" rc(3) = %f \n",sqrt(3));
    printf("entrer n : ");
    scanf("%d",&n);
    printf("valeur de U%d = %f",n,suite1_rec(n));
    return 0;
}


float suite1_rec(int n)
{
    if(n <=0)
        return 1;
    else
        return sqrt(1+suite1_rec(n-1));
}
