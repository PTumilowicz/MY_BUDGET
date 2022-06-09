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
