#include <stdio.h>
#include <stdlib.h>

int cat_def(int n);
int cat_for(int n);
int fact(int n);
int cat_math(int n);

void test_fonc(int t[], int n);


int main()
{
    int liste[] = {1,2,3,4,5,6,7,8};
    test_fonc(liste,8);

//    printf(" %d \n",fact(8));
//    printf("Hello world!\n");

//    printf(" %d \n",cat_math(3));
    return 0;
}

int cat_def(int n)
{
 if(n <= 1)
    return 1;
 else
    return ((4*n-6)/n)*cat_def(n-1);
}

int cat_for(int n)
{
    if(n <= 1)
        return 1;
    else
        return (fact(2*n - 2))/(fact(n-1)*fact(n));

}

int fact(int n)
{
    if(n <= 1)
        return 1;
    else
        return n*fact(n-1);
}

void test_fonc(int t[], int n)
{
    int i;

    printf("\n formule de catalan : cat(n) = ((4n-6)/n)*cat(n-1)\n");
    for(i = 0; i<n; i++)
        printf(" %d ", cat_def(t[i]));
    printf("\n\n formule de catalan : cat(n) = (2n-2)!/((n-1)!*(n)!)\n");
    for(i = 0; i<n; i++)
        printf(" %d ", cat_for(t[i]));
    printf("\n\n formule de catalan : cat(n) = S(k=0; n)cat(k)*cat(n-k)\n");
    for(i = 0; i<n; i++)
        printf(" %d ", cat_math(t[i]));

}

int cat_math(int n)
{
    int i, cata = 0;

    if(n<=1)
    {
        return 1;
    }
    else
    {
        for(i=0; i<n; i++)
        {
            cata = cata + cat_math(i)*cat_math(n-i-1);
        }
        return cata;
    }
}

