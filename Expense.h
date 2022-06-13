#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>
#include <regex>
#include <string>

#include "AuxilaryMethods.h"

using namespace std;

class Expense {
    int expenseId;
    int userId;
    int expenseDate;
    string expenseItem;
    double expenseAmount;

public:
    Expense(int expenseId = 0, int userId = 0, int expenseDate = 0, string expenseItem = "", double expenseAmount = 0.0) {
        this->expenseId = expenseId;
        this->userId = userId;
        this->expenseDate = expenseDate;
        this->expenseItem = expenseItem;
        this->expenseAmount = expenseAmount;
    }

    int getExpenseId();
    int getUserId();
    int getExpenseDate();
    string getExpenseItem();
    string getExpenseAmount();

    void setExpenseId(int newExpenseId);
    void setUserId(int newUserId);
    void setExpenseDate(int newExpenseDate);
    void setExpenseItem(string newExpenseItem);
    void setExpenseAmount(string newExpenseAmount);
};

#endif
