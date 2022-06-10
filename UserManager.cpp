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
    User user;
    int lastUserId = 0;

    if (users.size() == 0) {
        user.setUserId(1);
    } else {
        lastUserId = users.back().getUserId();
        user.setUserId(++lastUserId);
    }

    cout << "Enter user data" << endl;
    cout << "Enter first name: ";
    user.setUserFirstName(AuxilaryMethods::readLine());
    cout << "Enter last name: ";
    user.setUserLastName(AuxilaryMethods::readLine());
    cout << "Enter login: ";
    user.setUserLogin(AuxilaryMethods::readLine());
    cout << "Enter password: ";
    user.setUserPassword(AuxilaryMethods::readLine());

    return user;
}

void UserManager::logInUser() {

}


