#ifndef PLATEAU_H
#define PLATEAU_H

#include <iostream>
#include <string>

using namespace std;

class Plateau
{
private:
    /* data */
public:
    Plateau(/* args */);
    ~Plateau();
};

Plateau::Plateau(/* args */)
{
}

Plateau::~Plateau()
{
}

class PlateauAge : public Plateau
{
private:
    /* data */
public:
    PlateauAge(/* args */);
    ~PlateauAge();
};

PlateauAge::PlateauAge(/* args */)
{
}

PlateauAge::~PlateauAge()
{
}

class PlateauMerveille : public Plateau
{
private:
    /* data */
public:
    PlateauMerveille(/* args */);
    ~PlateauMerveille();
};

PlateauMerveille::PlateauMerveille(/* args */)
{
}

PlateauMerveille::~PlateauMerveille()
{
}

class PlateauJetonMilit : public Plateau
{
private:
    /* data */
public:
    PlateauJetonMilit(/* args */);
    ~PlateauJetonMilit();
};

PlateauJetonMilit::PlateauJetonMilit(/* args */)
{
}

PlateauJetonMilit::~PlateauJetonMilit()
{
}


#endif /* PLATEAU_H */