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

    void showHomeMenu();

    void registerUser();
    void loginUser();
    void logoutUser();
    void changePassword();

    void showMainMenu();

    void addIncome();
    void addExpense();

    void showBalance(int startDate, int endDate);

    int beginOfCurrentMonth();
    int endOfCurrentMonth();
    int beginOfLastMonth();
    int endOfLastMonth();

public:
    MyBudget(string userFileName, string incomeFileName, string expenseFileName)
    : userManager(userFileName), INCOME_FILE_NAME(incomeFileName), EXPENSE_FILE_NAME(expenseFileName) {

    }

    void chooseOptionInLogMenu();
};

#endif
