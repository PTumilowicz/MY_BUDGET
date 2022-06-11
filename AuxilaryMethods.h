#ifndef AUXILARYMETHODS_H
#define AUXILARYMETHODS_H

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

class AuxilaryMethods {
public:
    static char getCharacter();
    static string readLine();
    static string convIntToStr(int number);
    static int convStrToInt(string number);
};

#endif
