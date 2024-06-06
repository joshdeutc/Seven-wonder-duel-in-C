#ifndef JEU_H
#define JEU_H

#include <iostream>
#include <string>

#include "carte_bat_merv.h"

using namespace std;

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
    Batiment** getTabCartesAge1() const { return tabCartesAge1; }
    Batiment** getTabCartesAge2() const { return tabCartesAge2; }
    Batiment** getTabCartesAge3() const { return tabCartesAge3; }
    Guilde** getTabCartesGuilde() const { return tabCartesGuilde; }
    Merveille** getTabCartesMerveille() const { return tabCartesMerveille; }
    JetonProgres** getTabJetonProgres() const { return tabJetonProgres; }
};



#endif /* JEU_H */