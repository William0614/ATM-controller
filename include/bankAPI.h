#ifndef BANK_API_H
#define BANK_API_H

#include <string>
#include <unordered_map>
#include <vector>
#include "account.h"
#include "card.h"

class BankAPI {
public:
    BankAPI();

    void addCardAndPin(const std::string& cardNumber, const std::string& pin);
    bool verifyPin(const std::string& cardNumber, const std::string& pin);

    void addAccount(const std::string& accountNumber, int balance);
    std::vector<Account> getAccountsForCard(const std::string& cardNumber);

    // Added methods
    int getBalance(const std::string& accountNumber) const;
    void deposit(const std::string& accountNumber, int amount);
    bool withdraw(const std::string& accountNumber, int amount);
    Account* getAccountByNumber(const std::string& accountNumber);


private:
    std::unordered_map<std::string, std::string> cardToPin;  // Stores cardNumber -> pin
    std::unordered_map<std::string, std::vector<Account>> cardToAccounts;  // Stores cardNumber -> linked accounts
    std::unordered_map<std::string, Account> accounts;  // Stores accountNumber -> Account
};

#endif // BANK_API_H
