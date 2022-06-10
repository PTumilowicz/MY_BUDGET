#include <iostream>
#include <vector>

#include "User.h"
#include "UserFile.h"
#include "AuxilaryMethods.h"

using namespace std;

class UserManager {
    int loggedUserId;
    vector <User> users;
    UserFile userFile;

    User enterNewUserData();

public:
    UserManager(string userFileName) : userFile(userFileName) {
        loggedUserId = 0;
        users = userFile.loadUsersFromFile();
    };

    int getLoggedUserId();
    void setLoggedUserId(int newId);

    void registerUser();
    void logInUser();
};
