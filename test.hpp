#pragma once

#include <iostream>
#include <string>

using namespace std;

class ClasseMere
{
private:
public:
    int mere = 0;
    ClasseMere(/* args */);
    ~ClasseMere();
};

ClasseMere::ClasseMere(/* args */)
{
}

ClasseMere::~ClasseMere()
{
}


class ClasseFille : public ClasseMere
{
private:
public:
    int fille = 1;
    ClasseFille(int i = 0);
    ~ClasseFille();
    void hello(){cout << "Hello" << endl;};
    void change(int i) {fille = i;};
};

ClasseFille::ClasseFille(int i)
{
    mere = i;
}

ClasseFille::~ClasseFille()
{
}
