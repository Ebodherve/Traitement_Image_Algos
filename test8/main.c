#include <stdio.h>
#include <stdlib.h>

typedef struct couple
{
    int x;
    int y;
}couple;

void affiche_lab_1(char labr[17][11], int colonnes, int lignes);

void affiche_lab_2(char labr[], int colonnes, int lignes);

//void affiche_lab_2(char labr[], couple taille, couple coord);

int test_couple(couple couple_1, couple couple_2);

int main()
{
    char labr_1[17][11] = {"+---------------+",
                           "|               |",
                           "|               |",
                           "|               |",
                           "|               |",
                           "|               |",
                           "|               |",
                           "|               |",
                           "|               |",
                           "|               |",
                           "+---------------+"};
                       //taille 17-colonnes , 11 - lignes


   char labr_2[] = "+---------------+|               ||               ||               ||               ||               ||               ||               ||               ||               |+---------------+";


//    affiche_lab_1(labr_1, 17,11);
    affiche_lab_2(labr_2, 17,11);
    printf("Hello world!\n");
    return 0;

}

void affiche_lab_1(char labr[17][11], int colonnes, int lignes)
{
    int i,j;
    for(i=0; i<lignes; i++)
    {
        for(j=0; j<colonnes; j++)
        {
            printf("%c",labr[lignes][colonnes]);
            }
    printf("\n");
        }
}


void affiche_lab_2(char labr[], int colonnes, int lignes)
{
    int i,j = 0;
    for(i=0; i<(lignes*colonnes); i++)
    {
            j++;
            printf("%c",labr[i]);
            if(j == colonnes)
            {
                printf("\n");
                j=0;
            }
        }
}

/*void affiche_lab_2(char labr[], couple taille, couple coord)
{
    int i,j = 0;
    for(i=0; i<((taille.x)*(taille.y)); i++)
    {
            j++;

//            if(!test_couple())
            printf("%c",labr[i]);

            if(j == taille.y)
            {
                printf("\n");
                j=0;
            }

        }
}
*/

int test_couple(couple couple_1, couple couple_2)
{
    if((couple_1.x != couple_2.x) || (couple_1.y != couple_2.y))
        return 0;

    return 1;
}
