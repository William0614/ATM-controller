#include "../include/account.h"

Account::Account(std::string accNum, int initialBalance) 
    : accountNumber(accNum), balance(initialBalance) {}

std::string Account::getAccountNumber() const {
    return accountNumber;
}

int Account::getBalance() const {
    return balance;
}

void Account::deposit(int amount) {
    balance += amount;
}

bool Account::withdraw(int amount) {
    if (amount > balance) {
        return false;
    }
    balance -= amount;
    return true;
}
