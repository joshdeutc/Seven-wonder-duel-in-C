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
    explicit Pioche(const Partie& j);
    bool estVide() const { return nb == 0; }
    size_t getNbCartes() const { return nb; }
    const Carte& piocher();
    Pioche() {};
    ~Pioche();
    Pioche(const Pioche& p) = delete;
    Pioche& operator=(const Pioche& p) = delete;
};

Pioche::Pioche(/* args */)
{
}

Pioche::~Pioche()
{
}


#endif /* PIOCHE_H */