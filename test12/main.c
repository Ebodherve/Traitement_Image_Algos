#include <stdio.h>
#include <stdlib.h>

//fonctions arithmetiques

int pgcd(int a,int b);
int ppcm(int a,int b);

int val_ab(int a);
int max(int a, int b);

void test1();
void test2();



int main()
{
    test1();
    test2();


    //printf("Hello world!\n");
    return 0;
}

void test1()
{
    int a,b;

    printf("Entrer la valeur du premier nombre : ");
    scanf("%d",&a);
    printf("Entrer la valeur du deuxieme nombre : ");
    scanf("%d",&b);

    printf("le pgcd de %d et %d est %d \n",a,b,pgcd(a,b));
}

void test2()
{
    int a,b;

    printf("Entrer la valeur du premier nombre : ");
    scanf("%d",&a);
    printf("Entrer la valeur du deuxieme nombre : ");
    scanf("%d",&b);

    printf("le ppcm de %d et %d est %d \n",a,b,ppcm(a,b));
}

int pgcd(int a,int b)
{
    if(a == 0 || b == 0)
        return val_ab(a)+val_ab(b);

    if(a==1 || b==1 )
        return 1;

    int c = max(val_ab(a),val_ab(b)) , d = val_ab(b)+val_ab(a) - c,cons;

    while(d != 0)
    {
        cons = d;
        d = c%d;
        c = cons;
    }

    return c;
}

int ppcm(int a,int b)
{
    if(a == 0 || b == 0)
        return 0;
    if(a==1 || b==1 )
        return val_ab(a)+val_ab(b)-1;

    return (val_ab(a)*val_ab(b))/pgcd(a,b);
}

int val_ab(int a)
{
    if(a>=0)
        return a;
    return (-1)*a;
}

int max(int a, int b)
{
    if(a>=b)
        return a;
    return b;
}


