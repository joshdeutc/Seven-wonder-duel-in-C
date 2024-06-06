#include "partie.h"
#include "jeu.h"

int main(int argc, char const *argv[])
{
    // lancement du jeu
    Jeu *j = Jeu::getInstance();
    PlateauAge platage = PlateauAge(3);
    platage.accessibilite();
    int choix;
    do {
        std::cout << "Fais ton choix: ";
        std::cin >> choix;
        if (choix != 22) {
            platage.destruction_carte_plateau_age3(choix);
        }
        cout << "on a détruit la carte " << choix << endl;
        platage.accessibilite();
    } while (choix != 22);return 0;
}