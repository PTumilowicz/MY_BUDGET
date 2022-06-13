#include <iostream>
#include <vector>
#include <algorithm>

#include "Income.h"
#include "Expense.h"
#include "IncomeFile.h"
#include "ExpenseFile.h"
#include "AuxilaryMethods.h"

using namespace std;

class BudgetManager {
    const int LOGGED_USER_ID;
    vector <Income> incomes;
    vector <Expense> expenses;
    IncomeFile incomeFile;
    ExpenseFile expenseFile;

    Income addNewIncomeData();
    Expense addNewExpenseData();
    bool checkDateFormat(string date);
    bool checkCashAmountFormat(string cashAmount);

    string convCashAmount(string cashAmount);
    void showBalanceMenu(int startDate, int endDate);

public:
    BudgetManager(string incomeFileName, string expenseFileName, int loggedUserId) :
        LOGGED_USER_ID(loggedUserId), incomeFile(incomeFileName), expenseFile(expenseFileName) {
        incomes = incomeFile.loadIncomeFromFile(LOGGED_USER_ID);
        expenses = expenseFile.loadExpenseFromFile(LOGGED_USER_ID);
    }

    void addIncome();
    void addExpense();

    void showBalance(int startDate, int endDate);
};
