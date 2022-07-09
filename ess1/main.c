#include <stdio.h>
#include <stdlib.h>
//#include <windowsx.h>

int main()
{
    char salut[40];
    printf("Bonjour a toi comment tu vas :\n");
    scanf("%s",salut);
    printf("Tu vient de dire : %s\n", salut);
    return 0;
}

