#ifndef DATEMETHODS_H
#define DATEMETHODS_H

#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <iomanip>

#include "AuxilaryMethods.h"

using namespace std;

class DateMethods {
public:
    static int currentDate();
    static string convIntDateToString(int date);
    static int convStringDateToInt(string date);
};

#endif
