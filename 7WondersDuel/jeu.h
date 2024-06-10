#ifndef JEU_H
#define JEU_H

#include <iostream>
#include <string>

#include "carte_bat_merv.h"

using namespace std;

constexpr int nbCartesAge1 = 23;
constexpr int nbCartesAge2 = 23;
constexpr int nbCartesAge3 = 20;
constexpr int nbCartesGuilde = 7; // Ajustez selon vos besoins
constexpr int nbCartesMerveille = 12; // Ajustez selon vos besoins
constexpr int nbJetonsProgres = 10;

class Jeu { // Singleton Jeu
private:
    friend class PlateauAge;
    static Jeu* instance;
    Jeu();
    Jeu(Jeu &other) = delete;
    virtual ~Jeu();
    void operator=(const Jeu &) = delete;

    Batiment** tabCartesAge1;
    Batiment** tabCartesAge2;
    Batiment** tabCartesAge3;
    Guilde** tabCartesGuilde;
    Merveille** tabCartesMerveille;
    JetonProgres** tabJetonProgres;

public:
    static Jeu* getInstance();
    static void freeInstance();
    int getNbCartesAge1() const { return nbCartesAge1; }
    int getNbCartesAge2() const { return nbCartesAge2; }
    int getNbCartesAge3() const { return nbCartesAge3; }
    int getNbCartesGuilde() const { return nbCartesGuilde; }
    int getNbCartesMerveille() const { return nbCartesMerveille; }
    int getNbJetonsProgres() const { return nbJetonsProgres; }
    Batiment** getTabCartesAge1() const { return tabCartesAge1; }
    Batiment** getTabCartesAge2() const { return tabCartesAge2; }
    Batiment** getTabCartesAge3() const { return tabCartesAge3; }
    Guilde** getTabCartesGuilde() const { return tabCartesGuilde; }
    Merveille** getTabCartesMerveille() const { return tabCartesMerveille; }
    JetonProgres** getTabJetonProgres() const { return tabJetonProgres; }
    Carte* rechercherCarte(string s) const;
    JetonProgres* rechercherJeton(string s) const;
};



#endif /* JEU_H */
