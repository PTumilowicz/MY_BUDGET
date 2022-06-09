#include <iostream>
#include <vector>

#include "User.h"
#include "UserFile.h"

using namespace std;

class UserManager {
    int loggedUserId;
    vector <User> users;
    UserFile userFile;

public:
    UserManager() {
        loggedUserId = 0;
    };

    int getLoggedUserId();
    void setLoggedUserId(int newId);

};
