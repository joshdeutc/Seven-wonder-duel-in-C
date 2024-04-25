#include "partie.h"
#include "jeu.h"

int main(int argc, char const *argv[])
{
    // Lancement du jeu
    Jeu *j = Jeu::getInstance();

    // Actions à réaliser pour le bon déroulement du jeu


    // Fermeture du jeu
    j->freeInstance();
    
    return 0;
}