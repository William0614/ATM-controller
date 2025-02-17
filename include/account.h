#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <stdexcept>

class Account {
public:
    Account() : accountNumber(""), balance(0) {}
    Account(const std::string& accountNumber, int balance);

    std::string getAccountNumber() const;
    int getBalance() const;

    void deposit(int amount);
    void withdraw(int amount);

private:
    std::string accountNumber;
    int balance;
};

#endif // ACCOUNT_H
