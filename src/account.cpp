#include "../include/account.h"
#include <stdexcept>

Account::Account(const std::string& accountNumber, int balance)
    : accountNumber(accountNumber), balance(balance) {}

std::string Account::getAccountNumber() const {
    return accountNumber;
}

int Account::getBalance() const {
    return balance;
}

void Account::deposit(int amount) {
    if (amount <= 0) throw std::invalid_argument("Amount must be positive.");
    balance += amount;
}

void Account::withdraw(int amount) {
    if (amount <= 0) throw std::invalid_argument("Amount must be positive.");
    if (amount > balance) throw std::invalid_argument("Insufficient funds.");
    balance -= amount;
}
