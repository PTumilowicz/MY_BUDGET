#include <iostream>

#include "UserManager.h"
#include "BudgetManager.h"

using namespace std;

class MyBudget {
    UserManager userManager;
    BudgetManager *budgetManager;
    const string INCOME_FILE_NAME;
    const string EXPENSE_FILE_NAME;

    void showLogMenu();

public:
    MyBudget(string userFileName, string incomeFileName, string expenseFileName) {}

    void chooseOptionInLogMenu();
};
