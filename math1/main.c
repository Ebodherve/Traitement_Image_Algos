#include <stdio.h>
#include <stdlib.h>

float puissance_r(float r, int n);

float suite1(int n); // Un = (1.25)^n - (1)

int main()
{
    int n;
//    printf("Hello world!\n");
    printf("entrez l'entier n : ");
    scanf("%d",&n);

    printf("la valeur de Un est : %f",suite1(n));

    return 0;
}


float puissance_r(float r, int n)
{
    if(n <= 0)
        return 1;
    return r*puissance_r(r,n-1);
}


float suite1(int n)
{
    return puissance_r(1.25,n) - 1;
}


