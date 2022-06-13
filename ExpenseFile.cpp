#include "ExpenseFile.h"

int ExpenseFile::getLastExpenseId() {
    return lastExpenseId;
}

vector <Expense> ExpenseFile::loadExpenseFromFile(int loggedUserId) {
    int userIdFromXML = 0, intDate = 0;
    string strDate = "";
    Expense expense;
    vector <Expense> expenses;

    if (xml.Load(EXPENSE_FILE_NAME)) {
        xml.FindElem();
        xml.IntoElem();

        while (xml.FindElem("Expense")) {
            xml.IntoElem();
            xml.FindElem("expenseId");
            lastExpenseId = atoi(MCD_2PCSZ(xml.GetData()));
            xml.FindElem("userId");
            userIdFromXML = atoi(MCD_2PCSZ(xml.GetData()));

            if (userIdFromXML != loggedUserId) {
                xml.OutOfElem();
                continue;
            }

            expense.setUserId(userIdFromXML);
            expense.setExpenseId(lastExpenseId);

            xml.FindElem("expenseDate");
            strDate = xml.GetData();
            intDate = AuxilaryMethods::convStrToInt(strDate.substr(0,4) + strDate.substr(5,2) + strDate.substr(8,2));
            expense.setExpenseDate(intDate);

            xml.FindElem("expenseItem");
            expense.setExpenseItem(xml.GetData());
            xml.FindElem("expenseAmount");
            expense.setExpenseAmount(xml.GetData());
            xml.OutOfElem();

            expenses.push_back(expense);
        }
    }

    return expenses;
}

void ExpenseFile::addExpense(Expense expense) {
    int intDate = expense.getExpenseDate();
    double dblExpenseAmount = 0;
    string formatedDate = "", strExpenseAmount = "";

    formatedDate = AuxilaryMethods::convIntDateToString(intDate);
    dblExpenseAmount = expense.getExpenseAmount();
    strExpenseAmount = AuxilaryMethods::convDoubleToString(dblExpenseAmount);

    if (!xml.Load(EXPENSE_FILE_NAME)) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    } else {
        xml.FindElem();
    }

    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("expenseId", expense.getExpenseId());
    xml.AddElem("userId", expense.getUserId());
    xml.AddElem("expenseDate", formatedDate);
    xml.AddElem("expenseItem", expense.getExpenseItem());
    xml.AddElem("expenseAmount", strExpenseAmount);

    xml.Save(EXPENSE_FILE_NAME);

    lastExpenseId++;

    cout << "Expense added correctly." << endl;
    system("pause");
}
