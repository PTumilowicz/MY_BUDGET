#include "User.h"

int User::getUserId() {
    return id;
}
string User::getUserFirstName() {
    return firstName;
}

string User::getUserLastName() {
    return lastName;
}

string User::getUserLogin() {
    return login;
}

string User::getUserPassword() {
    return password;
}

void User::setUserId(int newId) {
    if (newId > 0) {
        id = newId;
    }
}

void User::setUserFirstName(string newFirstName) {
    firstName = newFirstName;
}

void User::setUserLastName(string newLastName) {
    lastName = newLastName;
}

void User::setUserLogin(string newLogin) {
    login = newLogin;
}

void User::setUserPassword(string newPassword) {
    password = newPassword;
}
