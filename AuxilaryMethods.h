#ifndef AUXILARYMETHODS_H
#define AUXILARYMETHODS_H

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

class AuxilaryMethods {
public:
    static char getCharacter();
    static string readLine();
    static string convIntToStr(int number);
    static int convStrToInt(string number);
    static int currentDate();
};

#endif
