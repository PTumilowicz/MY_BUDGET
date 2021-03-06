#ifndef AUXILARYMETHODS_H
#define AUXILARYMETHODS_H

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <ctime>
#include <iomanip>

using namespace std;

class AuxilaryMethods {
public:
    static char getCharacter();
    static string readLine();
    static string convIntToStr(int number);
    static int convStrToInt(string number);
    static string convDoubleToString(double number);
    static int currentDate();
    static string convIntDateToString(int date);
    static int convStringDateToInt(string date);
};

#endif
