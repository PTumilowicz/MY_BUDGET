#ifndef INCOME_H
#define INCOME_H

#include <iostream>
#include <regex>
#include <string>
#include <iomanip>

#include "AuxilaryMethods.h"

using namespace std;

class Income {
    int incomeId;
    int userId;
    int incomeDate;
    string incomeItem;
    double incomeAmount;

public:
    Income(int incomeId = 0, int userId = 0, int incomeDate = 0, string incomeItem = "", double incomeAmount = 0.0) {
        this->incomeId = incomeId;
        this->userId = userId;
        this->incomeDate = incomeDate;
        this->incomeItem = incomeItem;
        this->incomeAmount = incomeAmount;
    }

    int getIncomeId();
    int getUserId();
    int getIncomeDate();
    string getIncomeItem();
    string getIncomeAmount();

    void setIncomeId(int newIncomeId);
    void setUserId(int newUserId);
    void setIncomeDate(int newIncomeDate);
    void setIncomeItem(string newIncomeItem);
    void setIncomeAmount(string newIncomeAmount);
};

#endif
