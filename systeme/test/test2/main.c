
#include <unistd.h> // pour open, write, read
#include <fcntl.h> // O_CREAT, O_WRONLY, O_TRUNC
#define taille 80
#include <stdio.h>

int main ( )
{
    int fd, nbcar;
    char buf[taille] ;
    //créer/ouvrir un fichier
    fd = open("fich.txt", O_CREAT| O_WRONLY | O_TRUNC);
    if(fd==-1)
    {
        write(2, "Erreur d’ouverture \n", 20);
        return 0 ;
    }
    write(1, "Ouverture avec succès \n" , 23);
    // écrire dans fich les données lues à partir du clavier
    while ((nbcar= read(0, buf, taille)) > 0)
    if( write(fd, buf, nbcar)== -1) return 0 ;
    return 0 ;
}

