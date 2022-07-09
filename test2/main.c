#include <stdio.h>
#include <stdlib.h>

int cat_math(int n);

int main()
{
    printf(" %d \n",cat_math(1));
    return 0;
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



