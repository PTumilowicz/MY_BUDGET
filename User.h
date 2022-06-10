#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User {
    int id;
    string firstName;
    string lastName;
    string login;
    string password;

public:
    User() {};

    int getUserId();
    string getUserFirstName();
    string getUserLastName();
    string getUserLogin();
    string getUserPassword();

    void setUserId(int newId);
    void setUserFirstName(string newFirstName);
    void setUserLastName(string newLastName);
    void setUserLogin(string newLogin);
    void setUserPassword(string newPassword);
};

#endif
