#include <stdio.h>
#include <stdlib.h>


struct abr_n
{
    int val;
    struct abr_n * enfants[10];
};

struct abr_n * init();
struct abr_n * init_val(int val);


int main()
{
    struct abr_n * racine = init_val(12);
    racine->enfants[0] = init_val(73);
    struct abr_n *affiche =racine->enfants[0];

    printf(" first value of the list %d \n\n\n",racine->val);
    printf(" the value of is first child is %d \n\n\n",affiche->val);
    //printf("Hello world!\n");

    return 0;
}

struct abr_n * init()
{
    int i;
    struct abr_n * creation = (struct abr_n *)malloc(sizeof(struct abr_n));
    for(i = 0; i<10; i++)
        creation->enfants[i] = NULL;

    return creation;

}

struct abr_n * init_val(int val)
{
    struct abr_n *creation = init();
    creation->val = val;
    return creation;
}


