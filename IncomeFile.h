#include <iostream>
#include <vector>

#include "Income.h"
#include "Markup.h"

using namespace std;

class IncomeFile {
    int lastIncomeId;
    string const INCOME_FILE_NAME;
    CMarkup xml;

public:
    IncomeFile(string incomeFileName) : INCOME_FILE_NAME(incomeFileName) {
        lastIncomeId = 0;
    }

    int getLastIncomeId();
    vector <Income> loadIncomeFromFile(int loggedUserId);

    void addIncome(Income income);
};
