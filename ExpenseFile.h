#include <iostream>
#include <vector>

#include "Expense.h"
#include "Markup.h"

using namespace std;

class ExpenseFile {
    int lastExpenseId;
    string const EXPENSE_FILE_NAME;
    CMarkup xml;

public:
    ExpenseFile(string expenseFileName) : EXPENSE_FILE_NAME(expenseFileName) {
        lastExpenseId = 0;
    }

    int getLastExpenseId();
    vector <Expense> loadExpenseFromFile(int loggedUserId);

    void addExpense(Expense expense);
};
