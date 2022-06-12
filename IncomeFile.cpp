#include "IncomeFile.h"

vector <Income> IncomeFile::loadIncomeFromFile() {
    Income income;
    vector <Income> incomes;

    if (xml.Load(INCOME_FILE_NAME)) {
        xml.FindElem();
        xml.IntoElem();

        while (xml.FindElem("Income")) {
            xml.IntoElem();
            xml.FindElem("incomeId");
            income.setIncomeId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem("userId");
            income.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem("incomeDate");
            income.setIncomeDate(xml.GetData());
            xml.FindElem("incomeItem");
            income.setIncomeItem(xml.GetData());
            xml.FindElem("incomeAmount");
            income.setIncomeAmount(atof(MCD_2PCSZ(xml.GetData())));
            xml.OutOfElem();

            incomes.push_back(income);
        }
    }

    return incomes;
}

void IncomeFile::addIncome(Income income) {
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
    xml.AddElem("incomeDate", income.getIncomeDate());
    xml.AddElem("incomeItem", income.getIncomeItem());
    xml.AddElem("incomeAmount", income.getIncomeAmount());

    xml.Save(INCOME_FILE_NAME);
}
