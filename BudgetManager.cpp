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
        cout << "Available range 2000-01-01 to end of current month: ";
        date = AuxilaryMethods::readLine();

        if (!checkDateFormat(date)) {
            cout << "Wrong data format or date out of range. Try again." << endl;
        }
    } while(!checkDateFormat(date));

    intDate = AuxilaryMethods::convStrToInt(date.substr(0,4) + date.substr(5,2) + date.substr(8,2));
    income.setIncomeDate(intDate);

    cout << "Enter income item: ";
    income.setIncomeItem(AuxilaryMethods::readLine());

    do {
        cout << "Enter income amount: ";
        incomeAmount = AuxilaryMethods::readLine();

        if (!checkIncomeAmountFormat(incomeAmount)) {
            cout << "Wrong income amount format. Try again." << endl;
        }
    } while (!checkIncomeAmountFormat(incomeAmount));

    income.setIncomeAmount(incomeAmount);

    return income;
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

bool BudgetManager::checkIncomeAmountFormat(string incomeAmount) {
    int stringLength = incomeAmount.length();
    size_t counter = 0;

    replace(incomeAmount.begin(), incomeAmount.end(), ',', '.');
    counter = count(incomeAmount.begin(), incomeAmount.end(), '.');

    if (counter > 1) {
        return false;
    }

    for (int i = 0; i < stringLength; i++) {
        if(!isdigit(incomeAmount[i]) && incomeAmount[i] != '.') {
            return false;
        }
    }
    return true;
}


