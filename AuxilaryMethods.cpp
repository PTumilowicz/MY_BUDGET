#include "AuxilaryMethods.h"

char AuxilaryMethods::getCharacter() {
    string givenString = "";
    char givenCharacter = (0);

    cin.sync();

    while(true) {
        getline(cin, givenString);

        if (givenString.length() == 1) {
            givenCharacter = givenString[0];
            break;
        }
        cout << "This is not a single character. Try again." << endl;
        system("pause");
    }
    return givenCharacter;
}

string AuxilaryMethods::readLine() {
    string input = "";
    getline(cin, input);
    return input;
}
