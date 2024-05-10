#include "test.hpp"

int main(int argc, char const *argv[])
{
    ClasseMere *Objmere = new ClasseMere();
    ClasseFille *Objfille = new ClasseFille(5);
    cout << Objmere->mere << endl;
    // cout << Objmere->fille << endl;
    cout << Objfille->mere << endl;
    cout << Objfille->fille << endl;
    
    ClasseMere* tab[1] = {Objfille};

    // tab[0]->hello();
    static_cast<ClasseFille*>(tab[0])->hello();
    return 0;
}
