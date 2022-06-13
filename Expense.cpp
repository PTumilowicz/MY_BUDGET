#include "Expense.h"

int Expense::getExpenseId() {
    return expenseId;
}

int Expense::getUserId() {
    return userId;
}

int Expense::getExpenseDate() {
    return expenseDate;
}

string Expense::getExpenseItem() {
    return expenseItem;
}

double Expense::getExpenseAmount() {
    return expenseAmount;
}

void Expense::setExpenseId(int newExpenseId) {
    if (newExpenseId > 0) {
        expenseId = newExpenseId;
    }
}

void Expense::setUserId(int newUserId) {
    if (newUserId > 0) {
        userId = newUserId;
    }
}

void Expense::setExpenseDate(int newExpenseDate) {
   expenseDate = newExpenseDate;
}

void Expense::setExpenseItem(string newExpenseItem) {
    expenseItem = newExpenseItem;
}

void Expense::setExpenseAmount(string newExpenseAmount) {
    expenseAmount = stod(newExpenseAmount);
}
