#ifndef INCOME_H
#define INCOME_H

#include <iostream>
#include <regex>
#include <string>

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
    double getIncomeAmount();

    void setIncomeId(int newIncomeId);
    void setUserId(int newUserId);
    void setIncomeDate(string newIncomeDate);
    void setIncomeItem(string newIncomeItem);
    void setIncomeAmount(double newIncomeAmount);
};

#endif
