#include "UserManager.h"

int UserManager::getLoggedUserId() {
    return loggedUserId;
}

void UserManager::setLoggedUserId(int newId) {
    if (newId > 0) {
        loggedUserId = newId;
    } else {
        cout << "Wrong id. Try again." << endl;
    }
}

void UserManager::registerUser() {
    User user;
    user = enterNewUserData();
    users.push_back(user);
    userFile.addUser(user);
}

User UserManager::enterNewUserData() {
    int lastUserId = 0;
    string inputLogin = "";
    User user;

    if (users.size() == 0) {
        user.setUserId(1);
    } else {
        lastUserId = users.back().getUserId();
        user.setUserId(++lastUserId);
    }

    system("cls");
    cout << ">>>> MyBudget - Register new user <<<<\n" << endl;
    cout << "Enter user data\n" << endl;
    cout << "Enter first name: ";
    user.setUserFirstName(AuxilaryMethods::readLine());
    cout << "Enter last name: ";
    user.setUserLastName(AuxilaryMethods::readLine());

    do {
        cout << "Enter login: ";
        inputLogin = AuxilaryMethods::readLine();
        if (checkIfLoginExist(inputLogin)) {
            cout << "Login already used. Try another." << endl;
        }
    } while (checkIfLoginExist(inputLogin));

    user.setUserLogin(inputLogin);

    cout << "Enter password: ";
    user.setUserPassword(AuxilaryMethods::readLine());

    cout << "\nAccount registered!\n" << endl;
    system("pause");

    return user;
}

bool UserManager::checkIfLoginExist(string inputLogin) {
    int vectorSize = users.size();

    for (int i = 0; i < vectorSize; i++) {
        if (users[i].getUserLogin() == inputLogin) {
            return true;
        }
    }
    return false;
}

void UserManager::loginUser() {
    int vectorSize = users.size();
    int userIndex = 0;
    string inputLogin = "", inputPassword = "";

    system("cls");
    cout << ">>>> MyBudget - Login <<<<\n" << endl;
    cout << "Enter your login: ";
    inputLogin = AuxilaryMethods::readLine();

    if (checkIfLoginExist(inputLogin)) {
        for (int i = 0; i < vectorSize; i++) {
            if (users[i].getUserLogin() == inputLogin) {
                userIndex = i;
                break;
            }
        }

        for (int i = 0; i < 3; i ++) {
            cout << "Enter your password: ";
            inputPassword = AuxilaryMethods::readLine();
            if (users[userIndex].getUserPassword() == inputPassword) {
                loggedUserId = users[userIndex].getUserId();
                cout << "Password correct. You will be redirected to Main Menu." << endl;
                system("pause");
                break;
            }

            cout << "Password incorrect. Try again. You have " << 2 - i << " more attempts." << endl;

            if (i == 2) {
                cout << "Login failed. You will be redirected to Home Menu." << endl;
                system("pause");
            }
        }
    } else {
        cout << "Login do not exist. Try again." << endl;
        system("pause");
    }
}

void UserManager::logoutUser() {
    loggedUserId = 0;
    cout << "\nYou will be logged out. See you again.\n" << endl;
    system("pause");
}

void UserManager::changePassword() {
    int vectorSize = users.size();
    int userIndex = 0;
    string oldPassword = "", newPassword = "";

    for (int i = 0; i < vectorSize; i++) {
        if (users[i].getUserId() == loggedUserId) {
            userIndex = i;
            break;
        }
    }

    system("cls");
    cout << ">>>> MyBudget - Change password <<<<\n" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "Enter your old password: ";
        oldPassword = AuxilaryMethods::readLine();

        if (users[userIndex].getUserPassword() == oldPassword) {
            cout << "Passwords match. Enter new password: ";
            newPassword = AuxilaryMethods::readLine();
            users[userIndex].setUserPassword(newPassword);
            userFile.changePasswordInXML(loggedUserId, newPassword);
            cout << "Password changed. You will be redirected to Main Menu." << endl;
            system("pause");
            break;
        }

        cout << "Password incorrect. Try again. You have " << 2 - i << " more attempts." << endl;

        if (i == 2) {
            cout << "\nChanging password failed. You will be redirected to Main Menu.\n" << endl;
            system("pause");
        }
    }
}


