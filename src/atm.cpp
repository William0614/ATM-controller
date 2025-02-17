#include "../include/atm.h"
#include "../include/bankAPI.h"
#include <stdexcept>
#include <iostream>

ATM::ATM(BankAPI* bankAPI) : bankAPI(bankAPI), currentCard(nullptr), currentAccount("") {}

void ATM::insertCard(Card* card) {
    currentCard = card;
}

bool ATM::isCardInserted() {
    return currentCard != nullptr;
}

void ATM::ejectCard() {
    currentCard = nullptr;
    currentAccount = "";
}

bool ATM::enterPin(const std::string& pin) {
    return bankAPI->verifyPin(currentCard->getCardNumber(), pin);
}

void ATM::selectAccount(const std::string& accountNumber) {
    currentAccount = accountNumber;
}

int ATM::checkBalance() const {
    return bankAPI->getBalance(currentAccount);
}

void ATM::deposit(int amount) {
    std::cout << "Before deposit: " << checkBalance() << " dollars.\n";
    bankAPI->deposit(currentAccount, amount);
    std::cout << "After deposit: " << checkBalance() << " dollars.\n";
}

void ATM::withdraw(int amount) {
    std::cout << "Before withdrawal: " << checkBalance() << " dollars.\n";
    if (bankAPI->withdraw(currentAccount, amount)) {
        std::cout << "After withdrawal: " << checkBalance() << " dollars.\n";
    } else {
        std::cout << "Insufficient funds.\n";
    }
}

std::vector<std::string> ATM::getLinkedAccounts() {
    if (currentCard != nullptr) {
        std::vector<Account> accounts = bankAPI->getAccountsForCard(currentCard->getCardNumber());
        std::vector<std::string> accountNumbers;
        for (const auto& account : accounts) {
            accountNumbers.push_back(account.getAccountNumber());
        }
        return accountNumbers;
    }
    return {};
}

Account* ATM::getSelectedAccount() {
    if (!currentAccount.empty()) {
        return bankAPI->getAccountByNumber(currentAccount); 
    }
    return nullptr; 
}
