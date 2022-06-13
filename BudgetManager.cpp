#include "BudgetManager.h"

void BudgetManager::addIncome() {
    Income income = addNewIncomeData();
    incomes.push_back(income);
    incomeFile.addIncome(income);
}

Income BudgetManager::addNewIncomeData() {
    int lastIncomeId = incomeFile.getLastIncomeId();
    int intDate = 0;
    string date = "", incomeAmount = "";
    Income income;

    income.setIncomeId(++lastIncomeId);
    income.setUserId(LOGGED_USER_ID);

    system("cls");
    cout << ">>>> MyBudget - Add New Income <<<<\n" << endl;
    cout << "Enter income details\n" << endl;

    do {
        cout << "Enter income date (date format YYYY-MM-DD)" << endl;
        cout << "Press 't' if you want to enter current date." << endl;
        cout << "Available range 2000-01-01 to end of current month: ";
        date = AuxilaryMethods::readLine();

        if (date == "t" || date == "T") {
            date = AuxilaryMethods::convIntDateToString(AuxilaryMethods::currentDate());
        }

        if (!checkDateFormat(date)) {
            cout << "\nWrong data format or date out of range. Try again.\n" << endl;
        }
    } while(!checkDateFormat(date));

    intDate = AuxilaryMethods::convStringDateToInt(date);
    income.setIncomeDate(intDate);

    cout << "Enter income item: ";
    income.setIncomeItem(AuxilaryMethods::readLine());

    do {
        cout << "Enter income amount: ";
        incomeAmount = convCashAmount(AuxilaryMethods::readLine());

        if (!checkCashAmountFormat(incomeAmount)) {
            cout << "Wrong income amount format. Try again." << endl;
        }
    } while (!checkCashAmountFormat(incomeAmount));

    income.setIncomeAmount(incomeAmount);

    return income;
}

void BudgetManager::addExpense() {
    Expense expense = addNewExpenseData();
    expenses.push_back(expense);
    expenseFile.addExpense(expense);
}

Expense BudgetManager::addNewExpenseData() {
    int lastExpenseId = expenseFile.getLastExpenseId();
    int intDate = 0;
    string date = "", expenseAmount = "";
    Expense expense;

    expense.setExpenseId(++lastExpenseId);
    expense.setUserId(LOGGED_USER_ID);

    system("cls");
    cout << ">>>> MyBudget - Add New Expense <<<<\n" << endl;
    cout << "Enter expense details\n" << endl;

    do {
        cout << "Enter expense date (date format YYYY-MM-DD)" << endl;
        cout << "Press 't' if you want to enter current date." << endl;
        cout << "Available range 2000-01-01 to end of current month: ";
        date = AuxilaryMethods::readLine();

        if (date == "t" || date == "T") {
            date = AuxilaryMethods::convIntDateToString(AuxilaryMethods::currentDate());
        }

        if (!checkDateFormat(date)) {
            cout << "\nWrong data format or date out of range. Try again." << endl;
        }
    } while(!checkDateFormat(date));

    intDate = AuxilaryMethods::convStringDateToInt(date);
    expense.setExpenseDate(intDate);

    cout << "Enter expense item: ";
    expense.setExpenseItem(AuxilaryMethods::readLine());

    do {
        cout << "Enter expense amount: ";
        expenseAmount = convCashAmount(AuxilaryMethods::readLine());

        if (!checkCashAmountFormat(expenseAmount)) {
            cout << "Wrong expense amount format. Try again." << endl;
        }
    } while (!checkCashAmountFormat(expenseAmount));

    expense.setExpenseAmount(expenseAmount);

    return expense;
}

bool BudgetManager::checkDateFormat(string date) {
    int currentDate = AuxilaryMethods::currentDate();
    int currentYear =  currentDate / 10000;
    int currentMonth = (currentDate - currentYear * 10000) / 100;
    //int currentDay = currentDate % 100;
    int year = 0, month = 0, day = 0;

    if (date.length() != 10) {
        return false;
    }

    if (!regex_match(date, regex("2[0-9]{3}-[0-1]{1}[0-9]{1}-[0-3]{1}[0-9]{1}"))) {
        return false;
    }

    year = AuxilaryMethods::convStrToInt(date.substr(0,4));
    month = AuxilaryMethods::convStrToInt(date.substr(5,2));
    day = AuxilaryMethods::convStrToInt(date.substr(8,2));

    if (year < 2000 || year > currentYear) {
        return false;
    }

    if (month > 12 || (year == currentYear && month > currentMonth)) {
        return false;
    }

    switch(month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        if (day > 31) {
            return false;
        }
        break;
    case 4: case 6: case 9: case 11:
        if (day > 30) {
            return false;
        }
        break;
    case 2:
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            if (day > 29) {
                return false;
            }
        }

        if (day > 28) {
            return false;
        }
        break;
    default:
        return false;
        break;
    }

    return true;
}

bool BudgetManager::checkCashAmountFormat(string cashAmount) {
    int stringLength = cashAmount.length();
    size_t counter = 0;

    counter = count(cashAmount.begin(), cashAmount.end(), '.');

    if (counter > 1) {
        return false;
    }

    for (int i = 0; i < stringLength; i++) {
        if(!isdigit(cashAmount[i]) && cashAmount[i] != '.') {
            return false;
        }
    }
    return true;
}

string BudgetManager::convCashAmount(string cashAmount) {
    replace(cashAmount.begin(), cashAmount.end(), ',', '.');

    return cashAmount;
}

void BudgetManager::showBalanceMenu(int startDate, int endDate) {
    system("cls");

    system("cls");
    cout << ">>>> MyBudget - Balance <<<<\n" << endl;
    cout << "Selected period: " << AuxilaryMethods::convIntDateToString(startDate) << " - " << AuxilaryMethods::convIntDateToString(endDate) << endl;
}

void BudgetManager::showBalance(int startDate, int endDate) {
    int incomesVectorSize = incomes.size();
    int expensesVectorSize = expenses.size();
    double incomesSum = 0, expensesSum = 0;

    sort(incomes.begin(), incomes.end(), [](Income& lhs, Income& rhs) {
        return lhs.getIncomeDate() < rhs.getIncomeDate();
    });

    sort(expenses.begin(), expenses.end(), [](Expense& lhs, Expense& rhs) {
        return lhs.getExpenseDate() < rhs.getExpenseDate();
    });

    showBalanceMenu(startDate, endDate);

    cout << "\nINCOMES SORTED BY DATE \n" << endl;
    for (int i = 0; i < incomesVectorSize; i++) {
        if (incomes[i].getIncomeDate() >= startDate && incomes[i].getIncomeDate() <= endDate) {
            cout << "Income date: " << AuxilaryMethods::convIntDateToString(incomes[i].getIncomeDate());
            cout << "\tIncome item: " << incomes[i].getIncomeItem();
            cout << "\tIncome amount: " << incomes[i].getIncomeAmount() << endl;
            incomesSum += incomes[i].getIncomeAmount();
        }
    }

    cout << "\nEXPENSES SORTED BY DATE \n" << endl;
    for (int i = 0; i < expensesVectorSize; i++) {
        if (expenses[i].getExpenseDate() >= startDate && expenses[i].getExpenseDate() <= endDate) {
            cout << "Income date: " << AuxilaryMethods::convIntDateToString(expenses[i].getExpenseDate());
            cout << "\tExpense item: " << expenses[i].getExpenseItem();
            cout << "\tExpense amount: " << expenses[i].getExpenseAmount() << '\n' << endl;
            expensesSum += expenses[i].getExpenseAmount();
        }
    }

    cout << "Icomes sum in selected period: " << incomesSum << " zl." << endl;
    cout << "Expenses sum in selected period: " << expensesSum << " zl." << endl;
    cout << "\nCash balance in selected period: " << incomesSum - expensesSum << " zl\n" << endl;

    system("pause");
}
