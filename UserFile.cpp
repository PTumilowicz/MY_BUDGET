#include "UserFile.h"

void UserFile::addUser(User user) {
    if (!xml.Load(USER_FILE_NAME)) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    } else {
        xml.FindElem();
    }

    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("id", user.getUserId());
    xml.AddElem("firstName", user.getUserFirstName());
    xml.AddElem("lastName", user.getUserLastName());
    xml.AddElem("login", user.getUserLogin());
    xml.AddElem("password", user.getUserPassword());

    xml.Save(USER_FILE_NAME);
}

vector <User> UserFile::loadUsersFromFile() {
    User user;
    vector <User> users;

    if (xml.Load(USER_FILE_NAME)) {
        xml.FindElem();
        xml.IntoElem();

        while (xml.FindElem("User")) {
            xml.IntoElem();
            xml.FindElem("id");
            user.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem("firstName");
            user.setUserFirstName(xml.GetData());
            xml.FindElem("lastName");
            user.setUserLastName(xml.GetData());
            xml.FindElem("login");
            user.setUserLogin(xml.GetData());
            xml.FindElem("password");
            user.setUserPassword(xml.GetData());
            xml.OutOfElem();

            users.push_back(user);
        }
    }

    return users;
}

void UserFile::changePasswordInXML(int userId, string newPassword) {

    if (xml.Load(USER_FILE_NAME)) {
        xml.FindElem();
        xml.IntoElem();

        while (xml.FindElem("User")) {
            xml.IntoElem();
            xml.FindElem("id");

            if (xml.GetData() == AuxilaryMethods::convIntToStr(userId)) {
                xml.FindElem("password");
                xml.SetData(newPassword);
                xml.Save(USER_FILE_NAME);
                break;
            }

            xml.OutOfElem();
        }
    }
}
