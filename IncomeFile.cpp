#include "IncomeFile.h"

int IncomeFile::getLastIncomeId() {
    return lastIncomeId;
}

vector <Income> IncomeFile::loadIncomeFromFile(int loggedUserId) {
    int userIdFromXML = 0, intDate = 0;
    string strDate = "";
    Income income;
    vector <Income> incomes;

    if (xml.Load(INCOME_FILE_NAME)) {
        xml.FindElem();
        xml.IntoElem();

        while (xml.FindElem("Income")) {
            xml.IntoElem();
            xml.FindElem("incomeId");
            lastIncomeId = atoi(MCD_2PCSZ(xml.GetData()));
            xml.FindElem("userId");
            userIdFromXML = atoi(MCD_2PCSZ(xml.GetData()));

            if (userIdFromXML != loggedUserId) {
                xml.OutOfElem();
                continue;
            }

            income.setUserId(userIdFromXML);
            income.setIncomeId(lastIncomeId);

            xml.FindElem("incomeDate");
            strDate = xml.GetData();
            intDate = AuxilaryMethods::convStrToInt(strDate.substr(0,4) + strDate.substr(5,2) + strDate.substr(8,2));
            income.setIncomeDate(intDate);

            xml.FindElem("incomeItem");
            income.setIncomeItem(xml.GetData());
            xml.FindElem("incomeAmount");
            income.setIncomeAmount(xml.GetData());
            xml.OutOfElem();

            incomes.push_back(income);
        }
    }

    return incomes;
}

void IncomeFile::addIncome(Income income) {
    int intDate = income.getIncomeDate();
    double dblIncomeAmount = 0;
    string formatedDate = "", strIncomeAmount = "";

    formatedDate = AuxilaryMethods::convIntDateToString(intDate);
    dblIncomeAmount = income.getIncomeAmount();
    strIncomeAmount = AuxilaryMethods::convDoubleToString(dblIncomeAmount);

    if (!xml.Load(INCOME_FILE_NAME)) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    } else {
        xml.FindElem();
    }

    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("incomeId", income.getIncomeId());
    xml.AddElem("userId", income.getUserId());
    xml.AddElem("incomeDate", formatedDate);
    xml.AddElem("incomeItem", income.getIncomeItem());
    xml.AddElem("incomeAmount", strIncomeAmount);

    xml.Save(INCOME_FILE_NAME);

    lastIncomeId++;

    cout << "Income added correctly." << endl;
    system("pause");
}
