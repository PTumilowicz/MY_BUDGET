#include "MyBudget.h"

void MyBudget::chooseOptionInLogMenu() {
    char choice;

    while(true) {
        if (userManager.getLoggedUserId() == 0) {
            showHomeMenu();

            choice = AuxilaryMethods::getCharacter();

            switch (choice) {
            case '1':
                loginUser();
                break;
            case '2':
                registerUser();
                break;
            case '9':
                cout << "\nSee you next time.\n";
                exit(0);
                break;
            default:
                cout << "\nCharacter not used. Try again.\n" << endl;
                system("pause");
                break;
            }
        } else {
            showMainMenu();

            choice = AuxilaryMethods::getCharacter();

            switch (choice) {
            case '1':
                addIncome();
                break;
            case '2':
                addExpense();
                break;
            case '3':
                showBalance(beginOfCurrentMonth(), endOfCurrentMonth());
                break;
            case '4':
                //showBalance(beginOfLastMonth(), endOfLastMonth());
                break;
            case '5':
                //startDate = selectStartDate();
                //endDate = selectEndDate();
                //showBalance(startDate, endDate);
                break;
            case '6':
                changePassword();
                break;
            case '8':
                logoutUser();
                break;
            default:
                cout << "\nCharacter not used. Try again.\n" << endl;
                system("pause");
                break;
            }
        }
    }
}

void MyBudget::showHomeMenu() {
    system("cls");

    cout << ">>>> MyBudget - Home Menu <<<<\n" << endl;
    cout << "Choose one of the following:\n" << endl;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "9. Close app\n" << endl;
}

void MyBudget::showMainMenu() {
    system("cls");

    cout << ">>>> MyBudget - Main Menu <<<<\n" << endl;
    cout << "Choose one of the following:\n" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Current month cash balance" << endl;
    cout << "4. Last month cash balance" << endl;
    cout << "5. Chosen period cash balance" << endl;
    cout << "-------------------------------" << endl;
    cout << "6. Change password" << endl;
    cout << "8. Logout\n" << endl;
}

void MyBudget::loginUser() {
    userManager.loginUser();

    if (userManager.ifUserLoggedIn()) {
        budgetManager = new BudgetManager(INCOME_FILE_NAME, EXPENSE_FILE_NAME, userManager.getLoggedUserId());
    }
}

void MyBudget::logoutUser() {
    userManager.logoutUser();
    delete budgetManager;
    budgetManager = NULL;
}

void MyBudget::registerUser() {
    userManager.registerUser();
}

void MyBudget::changePassword() {
    userManager.changePassword();
}

void MyBudget::addIncome() {
    budgetManager->addIncome();
}

void MyBudget::addExpense() {
    budgetManager->addExpense();
}

void MyBudget::showBalance(int startDate, int endDate) {
    budgetManager->showBalance(startDate, endDate);
}

int MyBudget::beginOfCurrentMonth() {
    int currentDate = AuxilaryMethods::currentDate();
    int beginMonthDate = ((currentDate / 100) * 100) + 1;;

    return beginMonthDate;
}

int MyBudget::endOfCurrentMonth() {
    int currentDate = AuxilaryMethods::currentDate();
    int yearNumber = currentDate / 10000, monthNumber = 0;
    int endMonthDay = 0;

    monthNumber = (currentDate - (yearNumber * 10000)) / 100;

    switch(monthNumber) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return endMonthDay = ((currentDate / 100) * 100) + 31;
        break;
    case 4: case 6: case 9: case 11:
        return endMonthDay = ((currentDate / 100) * 100) + 30;
        break;
    case 2:
        if ((yearNumber % 4 == 0 && yearNumber % 100 != 0) || yearNumber % 400 == 0) {
            return endMonthDay = ((currentDate / 100) * 100) + 29;
        }

        return endMonthDay = ((currentDate / 100) * 100) + 28;
        break;
    }
    return endMonthDay;
}
