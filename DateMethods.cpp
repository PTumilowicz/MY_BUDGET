#include "DateMethods.h"

int DateMethods::currentDate() {
    int year = 0, month = 0, day = 0;
    int currentDate = 0;

    time_t t = time(0);
    tm* now = localtime(&t);

    year = now->tm_year + 1900;
    month = now->tm_mon + 1;
    day = now->tm_mday;

    currentDate = year * 10000 + month * 100 + day;

    return currentDate;
}

string DateMethods::convIntDateToString(int date) {
    string strDate = AuxilaryMethods::convIntToStr(date);
    string formatedDate = strDate.substr(0,4) + '-' + strDate.substr(4,2) + '-' + strDate.substr(6,2);
    return formatedDate;
}

int DateMethods::convStringDateToInt(string date) {
    int intDate = AuxilaryMethods::convStrToInt(date.substr(0,4) + date.substr(5,2) + date.substr(8,2));
    return intDate;
}
