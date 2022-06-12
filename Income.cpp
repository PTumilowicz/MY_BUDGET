#include "Income.h"

int Income::getIncomeId() {
    return incomeId;
}

int Income::getUserId() {
    return userId;
}

int Income::getIncomeDate() {
    return incomeDate;
}

string Income::getIncomeItem() {
    return incomeItem;
}

double Income::getIncomeAmount() {
    return incomeAmount;
}

void Income::setIncomeId(int newIncomeId) {
    if (newIncomeId > 0) {
        incomeId = newIncomeId;
    }
}

void Income::setUserId(int newUserId) {
    if (newUserId > 0) {
        userId = newUserId;
    }
}

void Income::setIncomeDate(string newIncomeDate) {
    //incomeDate = newIncomeDate;
}

void Income::setIncomeItem(string newIncomeItem) {
    incomeItem = newIncomeItem;
}

void Income::setIncomeAmount(double newIncomeAmount) {
    incomeAmount = newIncomeAmount;
}
