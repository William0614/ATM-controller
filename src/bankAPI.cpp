#include "../include/bankAPI.h"
#include "../include/account.h"
#include <stdexcept>
#include <iostream>

BankAPI::BankAPI() {}

void BankAPI::addCardAndPin(const std::string& cardNumber, const std::string& pin) {
    cardToPin[cardNumber] = pin;
}

bool BankAPI::verifyPin(const std::string& cardNumber, const std::string& pin) {
    if (cardToPin.find(cardNumber) != cardToPin.end()) {
        return cardToPin[cardNumber] == pin;
    }
    return false;  // card not found
}

void BankAPI::addAccount(const std::string& accountNumber, int balance) {
    accounts[accountNumber] = Account(accountNumber, balance);  // Assuming Account has a constructor that accepts balance
}

std::vector<Account> BankAPI::getAccountsForCard(const std::string& cardNumber) {
    std::vector<Account> linkedAccounts;
    for (auto& pair : cardToAccounts) {
        for (auto& account : pair.second) {
            linkedAccounts.push_back(account);
        }
    }
    return linkedAccounts;
}

Account* BankAPI::getAccountByNumber(const std::string& accountNumber) {
    auto it = accounts.find(accountNumber);
    if (it != accounts.end()) {
        return &(it->second);  // Return pointer to Account
    }
    return nullptr;  // Return nullptr if account not found
}


int BankAPI::getBalance(const std::string& accountNumber) const {
    auto it = accounts.find(accountNumber);
    if (it != accounts.end()) {
        return it->second.getBalance();
    }
    std::cerr << "Account not found in getBalance().\n";
    return 0;
}


void BankAPI::deposit(const std::string& accountNumber, int amount) {
    auto it = accounts.find(accountNumber);
    if (it != accounts.end()) {
        it->second.deposit(amount);
    } else {
        std::cerr << "Account not found.\n";
    }
}

bool BankAPI::withdraw(const std::string& accountNumber, int amount) {
    auto it = accounts.find(accountNumber);
    if (it != accounts.end()) {
        try {
            it->second.withdraw(amount);
            return true;
        } catch (const std::invalid_argument& e) {
            return false;
        }
    }
    return false;
}
