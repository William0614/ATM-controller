#include <gtest/gtest.h>
#include "../include/atm.h"
#include "../include/bankAPI.h"
#include "../include/card.h"
#include "../include/account.h"

TEST(ATMTest, InsertCardAndVerifyPin) {
    BankAPI bank;
    ATM atm(&bank);
    Card card("1234567890");

    bank.addCardAndPin("1234567890", "1234");
    atm.insertCard(&card);
    EXPECT_TRUE(atm.enterPin("1234"));
    EXPECT_FALSE(atm.enterPin("0000"));
}

TEST(ATMTest, SelectAccount) {
    BankAPI bank;
    ATM atm(&bank);
    Card card("1234567890");

    bank.addCardAndPin("1234567890", "1234");
    bank.addAccount("ACC1001", 1000);

    atm.insertCard(&card);
    atm.enterPin("1234");

    atm.selectAccount("ACC1001");  

    Account* selectedAccount = atm.getSelectedAccount();
    ASSERT_NE(selectedAccount, nullptr);  
    EXPECT_EQ(selectedAccount->getAccountNumber(), "ACC1001");
}


TEST(ATMTest, CheckBalance) {
    BankAPI bank;
    ATM atm(&bank);
    Card card("1234567890");

    bank.addCardAndPin("1234567890", "1234");
    bank.addAccount("ACC1001", 1000);

    atm.insertCard(&card);
    atm.enterPin("1234");
    atm.selectAccount("ACC1001");

    int balance = atm.checkBalance();

    EXPECT_EQ(balance, 1000);
}

TEST(ATMTest, DepositMoney) {
    BankAPI bank;
    ATM atm(&bank);
    Card card("1234567890");

    bank.addCardAndPin("1234567890", "1234");
    bank.addAccount("ACC1001", 1000);

    atm.insertCard(&card);
    atm.enterPin("1234");
    atm.selectAccount("ACC1001");
    atm.deposit(500);

    EXPECT_EQ(atm.checkBalance(), 1500);
}

TEST(ATMTest, WithdrawMoney) {
    BankAPI bank;
    ATM atm(&bank);
    Card card("1234567890");

    bank.addCardAndPin("1234567890", "1234");
    bank.addAccount("ACC1001", 1000);

    atm.insertCard(&card);
    atm.enterPin("1234");
    atm.selectAccount("ACC1001");
    atm.withdraw(500);

    EXPECT_EQ(atm.checkBalance(), 500);
}

TEST(ATMTest, EjectCard) {
    BankAPI bank;
    ATM atm(&bank);
    Card card("1234567890");

    bank.addCardAndPin("1234567890", "1234");

    atm.insertCard(&card);
    atm.enterPin("1234");
    EXPECT_TRUE(atm.isCardInserted());

    atm.ejectCard();
    EXPECT_FALSE(atm.isCardInserted());
}
