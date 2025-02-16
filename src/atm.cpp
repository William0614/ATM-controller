#include "../include/atm.h"
#include <cctype>
#include <iostream>
#include <vector>

ATM::ATM(BankAPI* bankAPI) : bank(bankAPI), insertedCard(nullptr), selectedAccount(nullptr) {}

void ATM::insertCard(Card* card) {
    if (insertedCard) {
        std::cout << "Card already inserted.\n";
        return;
    }
    insertedCard = card;
    std::cout << "Card inserted. Enter your PIN.\n";
}


bool ATM::enterPin(std::string pin) {
    // Check if PIN is valid.
    for (char c : pin) {
        if (!isdigit(c)) {
            std::cout << "Invalid PIN. Enter only digits." << std::endl;
            return false;
        }
    }

    if (bank->verifyPin(insertedCard->getCardNumber(), pin)) return true;
    return false;
}


bool ATM::selectAccount(std::string accountNumber) {
    if (!insertedCard) return false;

    std::vector<std::string> accounts = bank->getAccounts(insertedCard->getCardNumber());
    if (accounts.empty()) return false;

    std::cout << "Select an account:\n";
    for (size_t i = 0; i < accounts.size(); ++i)
        std::cout << i + 1 << ". " << accounts[i] << "\n";

    int choice;
    std::cin >> choice;

    if (choice < 1 || choice > accounts.size()) return false;

    selectedAccount = bank->getAccount(accounts[choice - 1]);
    return true;
}

std::vector<std::string> ATM::getLinkedAccounts() {
    if (!insertedCard) {
        std::cout << "No card inserted.\n";
        return {};
    }
    return bank->getAccountsForCard(insertedCard->getCardNumber());
}

int ATM::checkBalance() {
    if (!selectedAccount) return -1;
    return selectedAccount->getBalance();
}

void ATM::deposit(int amount) {
    if (!selectedAccount || amount <= 0) return;
    selectedAccount->deposit(amount);
}

bool ATM::withdraw(int amount) {
    if (!selectedAccount || amount <= 0) return false;
    return selectedAccount->withdraw(amount);
}

void ATM::ejectCard() {
    insertedCard = nullptr;
    selectedAccount = nullptr;
}

// CLI Menu
// void ATM::showATMMenu() {
//     int choice;
//     std::string pin;
//     int amount;

//     while (true) {
//         std::cout << "\n===== ATM Menu =====\n";
//         std::cout << "1. Insert Card\n";
//         std::cout << "2. Enter PIN\n";
//         std::cout << "3. Select Account\n";
//         std::cout << "4. Check Balance\n";
//         std::cout << "5. Deposit\n";
//         std::cout << "6. Withdraw\n";
//         std::cout << "7. Eject Card\n";
//         std::cout << "8. Exit\n";
//         std::cin >> choice;

//         if (choice == 8) break;
//         if (choice == 1) insertCard(new Card("123456"));
//         if (choice == 2) { std::cin >> pin; enterPin(pin); }
//         if (choice == 3) selectAccount(std::string("ACC1001"));
//         if (choice == 4) std::cout << "Balance: $" << checkBalance() << "\n";
//         if (choice == 5) { std::cin >> amount; deposit(amount); }
//         if (choice == 6) { std::cin >> amount; withdraw(amount); }
//         if (choice == 7) ejectCard();
//     }
// }
