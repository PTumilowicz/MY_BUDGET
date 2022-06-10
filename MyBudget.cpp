#include "MyBudget.h"

void MyBudget::chooseOptionInLogMenu() {
    char choice;

    while(true) {
        if (userManager.getLoggedUserId() == 0) {
            showLogMenu();

            choice = AuxilaryMethods::getCharacter();

            switch (choice) {
            case '1':
                logInUser();
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
        }
    }
}

void MyBudget::showLogMenu() {
    system("cls");

    cout << ">>>> Welcome to MyBudget <<<<" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Choose one of the following:" << endl;
    cout << "1. Log In" << endl;
    cout << "2. Register" << endl;
    cout << "9. Close app" << endl;
}

void MyBudget::logInUser() {
    userManager.logInUser();
}

void MyBudget::registerUser() {
    userManager.registerUser();
}
