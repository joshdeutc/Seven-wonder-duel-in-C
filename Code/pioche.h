#ifndef PIOCHE_H
#define PIOCHE_H

#include <iostream>
#include <string>

using namespace std;

#include "carte.h"

class Pioche
{
private:
    const Carte** cartes = nullptr;
    size_t nb = 0;
public:
    Pioche(/* args */);
    ~Pioche();
};

Pioche::Pioche(/* args */)
{
}

Pioche::~Pioche()
{
}


#endif /* PIOCHE_H */