#include <iostream>
#include <vector>

#include "Income.h"
#include "Expense.h"
#include "IncomeFile.h"
#include "ExpenseFile.h"

using namespace std;

class BudgetManager {
    const int LOGGED_USER_ID;
    vector <Income> incomes;
    vector <Expense> expenses;
    IncomeFile incomeFile;
    ExpenseFile expenseFile;

public:
    BudgetManager(string incomeFileName, string expenseFileName, int loggedUserId) :
        LOGGED_USER_ID(loggedUserId), incomeFile(incomeFileName) {
        incomes = incomeFile.loadIncomeFromFile();
    }

    void addIncome();
};
