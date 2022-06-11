#include <iostream>
#include <vector>

#include "Markup.h"
#include "User.h"
#include "AuxilaryMethods.h"

using namespace std;

class UserFile {
    string const USER_FILE_NAME;
    CMarkup xml;

public:
    UserFile(string userFileName) : USER_FILE_NAME(userFileName) {
    };

    vector <User> loadUsersFromFile();
    void addUser(User user);
    void changePasswordInXML(int userId, string newPassword);

};
