#ifndef wondersException_hpp
#define wondersException_hpp

#include <string>
using namespace std;

class WondersException{
    string info;
public:
    WondersException(const string &s):info(s){}
    const string& getInfo() const {return info;}
};

#endif