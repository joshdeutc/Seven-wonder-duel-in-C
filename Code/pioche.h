#ifndef PIOCHE_H
#define PIOCHE_H

#include <iostream>
#include <string>

using namespace std;

#include "carte.h"
#include "partie.h"

class Pioche
{
private:
    const Carte** cartes = nullptr;
    size_t nb = 0;
public:
    Pioche(Partie& p);
    ~Pioche();
};

Pioche::Pioche(/* args */)
{
}

Pioche::~Pioche()
{
}


#endif /* PIOCHE_H */