#include <iostream>
#include "../include/atm.h"
#include "../include/bankAPI.h"
#include "../include/card.h"

int main() {
    BankAPI bank;
    ATM atm(&bank);
    std::string cardNumber, pin, accountNumber;
    
    // Step 1: Insert Card
    std::cout << "Insert your card (Enter card number): ";
    std::cin >> cardNumber;
    Card userCard(cardNumber);
    atm.insertCard(&userCard);

    // Step 2: Enter PIN (Only digits allowed)
    while (true) {
        std::cout << "Enter PIN: ";
        std::cin >> pin;

        if (pin.find_first_not_of("0123456789") != std::string::npos) {
            std::cout << "Invalid PIN. Only digits allowed.\n";
            continue;
        }

        if (!atm.enterPin(pin)) {
            std::cout << "Incorrect PIN.\n";
        } else {
            std::cout << "Correct PIN.\n";
            break;
        }
    }
    
    // Step 3: Select Account
    std::vector<std::string> accounts = atm.getLinkedAccounts();  // Get user's accounts

    if (accounts.empty()) {
        std::cout << "No accounts. Ejecting card.\n";
        atm.ejectCard();
        return 0;
    }

    std::cout << "Select an account:\n";
    for (size_t i = 0; i < accounts.size(); i++) {
        std::cout << i + 1 << ". " << accounts[i] << "\n";
    }

    int accountChoice;
    while (true) {
        std::cout << "Enter account number: ";
        std::cin >> accountChoice;

        if (accountChoice >= 1 && accountChoice <= accounts.size()) {
            atm.selectAccount(accounts[accountChoice - 1]);
            break;
        } else {
            std::cout << "Invalid. Try again.\n";
        }
    }

    // Step 4: Transaction Menu
    while (true) {
        std::cout << "\nSelect an option:\n";
        std::cout << "1. Check Balance\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw Money\n";
        std::cout << "4. Eject Card\n";
        std::cout << "Enter choice: ";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            atm.checkBalance();
        } else if (choice == 2) {
            int amount;
            std::cout << "Deposit amount: ";
            std::cin >> amount;
            atm.deposit(amount);
        } else if (choice == 3) {
            int amount;
            std::cout << "Withdrawal amount: ";
            std::cin >> amount;
            atm.withdraw(amount);
        } else if (choice == 4) {
            atm.ejectCard();
            std::cout << "Card ejected.\n";
            break;
        } else {
            std::cout << "Invalid. Try again.\n";
        }
    }

    return 0;
}
