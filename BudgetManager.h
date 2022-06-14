#include <iostream>
#include <vector>
#include <algorithm>

#include "Income.h"
#include "Expense.h"
#include "IncomeFile.h"
#include "ExpenseFile.h"
#include "AuxilaryMethods.h"
#include "DateMethods.h"

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

    void showBalance(int startDate, int endDate);
    void showBalanceMenu(int startDate, int endDate);

    int beginOfMonth(int date);
    int endOfMonth(int date);
    int beginOfLastMonth();
    int endOfLastMonth();

public:
    BudgetManager(string incomeFileName, string expenseFileName, int loggedUserId) :
        LOGGED_USER_ID(loggedUserId), incomeFile(incomeFileName), expenseFile(expenseFileName) {
        incomes = incomeFile.loadIncomeFromFile(LOGGED_USER_ID);
        expenses = expenseFile.loadExpenseFromFile(LOGGED_USER_ID);
    }

    void addIncome();
    void addExpense();

    void showCurrentMonthBalance();
    void showLastMonthBalance();
    void showSelectedPeriodBalance();
};
