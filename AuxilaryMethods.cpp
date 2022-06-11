#include "AuxilaryMethods.h"

char AuxilaryMethods::getCharacter() {
    string input = "";
    char givenCharacter = (0);

    cout << "Your choice: ";

    cin.sync();

    while(true) {
        getline(cin, input);

        if (input.length() == 1) {
            givenCharacter = input[0];
            break;
        }
        cout << "This is not a single character. Try again." << endl;
        system("pause");
    }

    return givenCharacter;
}

string AuxilaryMethods::readLine() {
    string input = "";

    cin.sync();

    while(true) {
        getline(cin, input);

        if (input.length() != 0) {
            break;
        }

        cout << "You have entered empty string. Try again." << endl;
        system("pause");
    }

    return input;
}

string AuxilaryMethods::convIntToStr(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();

    return str;
}

int AuxilaryMethods::convStrToInt(string number) {
    int intNumber = 0;
    istringstream iss(number);
    iss >> intNumber;

    return intNumber;
}
