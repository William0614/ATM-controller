#ifndef BANKAPI_H
#define BANKAPI_H

#include <unordered_map>
#include <vector>
#include "account.h"

class BankAPI {
private:
    std::unordered_map<std::string, std::string> cardToPin;
    std::unordered_map<std::string, std::vector<std::string> > cardToAccounts;
    std::unordered_map<std::string, Account> accounts;

public:
    BankAPI();
    
    bool verifyPin(const std::string& cardNumber, const std::string& pin);
    std::vector<std::string> getAccounts(const std::string& cardNumber);
    std::vector<std::string> getAccountsForCard(const std::string& cardNumber);
    Account* getAccount(const std::string& accountNumber);
};

#endif
