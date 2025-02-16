#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

class Account {
private:
    std::string accountNumber;
    int balance;

public:
    Account() : accountNumber(""), balance(0) {}
    Account(std::string accNum, int initialBalance);
    
    std::string getAccountNumber() const;
    int getBalance() const;
    
    void deposit(int amount);
    bool withdraw(int amount);
};

#endif