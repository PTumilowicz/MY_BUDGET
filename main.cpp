#include <iostream>

#include "MyBudget.h"

using namespace std;

int main()
{
    MyBudget myBudget("users.xml", "incomes.xml", "expenses.xml");
    myBudget.chooseOptionInLogMenu();
    return 0;
}
