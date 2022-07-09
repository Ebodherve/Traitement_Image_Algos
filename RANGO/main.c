#include <stdio.h>
#include <stdlib.h>

struct mot
{
    char letter;
    struct mot * suiv;
};


int main()
{
    printf("Hello world!\n");
    return 0;
}
