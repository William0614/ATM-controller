#ifndef ATM_H
#define ATM_H

#include <string>
#include <vector>
#include "card.h"
#include "account.h"
#include "bankAPI.h"

#include <vector>
#include <string>
#include "card.h"
#include "bankAPI.h"

class ATM {
public:
    ATM(BankAPI* bankAPI);
    void insertCard(Card* card);
    bool enterPin(const std::string& pin);
    void selectAccount(const std::string& accountNumber);
    int  checkBalance() const;
    void deposit(int amount);
    void withdraw(int amount);
    void ejectCard();
    bool isCardInserted();
    
    std::vector<std::string> getLinkedAccounts();
    Account* getSelectedAccount();

private:
    BankAPI* bankAPI;
    Card* currentCard;
    std::string currentAccount;
};

#endif // ATM_H