#include <stdio.h>
#include <stdlib.h>
//#include <control.h>
#include <conio.h>
//#include <condition_variable>


int puissance(int a, int b);
int binaire(int nombre);
int taille(int nombre);
void test1();
void test2();

int main()
{
//    test1();
//test2();
//test3();

    char car[10];
    int i;
    void * s;


    for(i = 0; i<10; i++)
    {
         printf("caractere %d ", i+1);
         scanf("%c",&car[i]);
         scanf("%c",&s);
    }

    printf("\n\n\n caracteres : \n");

    for(int i = 0; i<10; i++)
    printf(" %c : %d = %d \n",car[i],binaire(car[i]),car[i]);


//    printf("Hello world!\n");

    return 0;
}

void test1()
{
    int nombre;

    printf("entrer un nombre ");
    scanf("%d",&nombre);
    printf("taille en binaire %d ",taille(nombre));

}

void test2()
{
    int nombre;

    printf("entrer un nombre ");
    scanf("%d",&nombre);
    printf("conversion binaire %d ",binaire(nombre));

}

void test3()
{
    int nombre1, nombre2;

    printf("entrer le nombre 1 : ");
    scanf("%d",&nombre1);
    printf("entrer le nombre 2 : ");
    scanf("%d",&nombre2);
    printf("%d a la puissance %d = %d ",nombre1,nombre2,puissance(nombre1,nombre2));

}

int taille(int nombre)
{
    if(nombre<2)
        return 1;
    else
    {
        int cpt = 1,nv_ap = 2;

        while(nv_ap <=nombre)
        {
            nv_ap *=2;
            cpt += 1;
        }
        return cpt;

    }
}

int binaire(int nombre)
{
    if(nombre < 0)
        return -1*binaire(nombre*-1);
    else if(nombre==0)
        return 0;
    else if(nombre==1)
        return 1;
    else
    {
        const int taille_b = taille(nombre);
        int i,bits[taille_b],nv_n = nombre;

        for(i = 0; i<taille_b; i++)
            {
                bits[i] = nv_n%2;
                nv_n = nv_n/2;
            }
            nv_n = 0;
        for(i = 0; i<taille_b; i++)
            nv_n += bits[taille_b-i-1]*puissance(10,taille_b-i-1);

        return nv_n;

    }

}

int puissance(int a,int b)
{
    int nombre = 1;
    for(int i = 0; i<b; i++)
        nombre*=a;

        return nombre;

}

