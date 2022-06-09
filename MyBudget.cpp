#include "MyBudget.h"

void MyBudget::chooseOptionInLogMenu() {
    char choice;

    if (userManager.getLoggedUserId() == 0) {
        showLogMenu();
    }
}

void MyBudget::showLogMenu() {
    cout << ">>>> Welcome to MyBudget <<<<" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Choose one of the following:" << endl;
    cout << "1. Log In" << endl;
    cout << "2. Register" << endl;
    cout << "9. Close app" << endl;
}
