#ifndef MYBUDGET_H
#define MYBUDGET_H

#include <iostream>

#include "AuxilaryMethods.h"
#include "UserManager.h"
#include "BudgetManager.h"

using namespace std;

class MyBudget {
    UserManager userManager;
    BudgetManager *budgetManager;
    const string INCOME_FILE_NAME;
    const string EXPENSE_FILE_NAME;

    void showLogMenu();

    void registerUser();
    void logInUser();

public:
    MyBudget(string userFileName, string incomeFileName, string expenseFileName) : userManager(userFileName){

    }

    void chooseOptionInLogMenu();
};

#endif
