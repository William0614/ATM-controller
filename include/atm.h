#ifndef ATM_H
#define ATM_H

#include <iostream>
#include "account.h"
#include "card.h"
#include "bankAPI.h"

class ATM {
private:
    BankAPI* bank;
    Card* insertedCard;
    Account* selectedAccount;

public:
    ATM(BankAPI* bankAPI);

    void insertCard(Card* card);
    bool enterPin(std::string pin);
    bool selectAccount(std::string accountNumber);
    int checkBalance();
    void deposit(int amount);
    bool withdraw(int amount);
    void ejectCard();
    std::vector<std::string> getLinkedAccounts();
    void showATMMenu();
};

#endif
