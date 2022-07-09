#include <unistd.h> /* pour write */
#include <stdio.h> /* pour printf*/
int main( ) {
    printf(" ici1er printf");
    write(1," ici1er write ",16);
    printf(" ici2eme printf");
    write(1," ici2eme write ", 17);
    printf("fin de lignede printf\n");
    write(1, " ici3eme write \n",17);

    return 0;
}
