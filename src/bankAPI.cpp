#include "../include/bankAPI.h"

BankAPI::BankAPI() {
    cardToPin["123456"] = "1111";
    cardToAccounts["123456"] = {"ACC1001"};
    accounts["ACC1001"] = Account("ACC1001", 1000);
}

bool BankAPI::verifyPin(const std::string& cardNumber, const std::string& pin) {
    return cardToPin.find(cardNumber) != cardToPin.end() && cardToPin[cardNumber] == pin;
}

std::vector<std::string> BankAPI::getAccounts(const std::string& cardNumber) {
    if (cardToAccounts.find(cardNumber) != cardToAccounts.end()) {
        return cardToAccounts[cardNumber];
    }
    return {};
}

std::vector<std::string> BankAPI::getAccountsForCard(const std::string& cardNumber) {
    std::vector<std::string> linkedAccounts;

    // Check if card exists in the map
    if (cardToAccounts.find(cardNumber) != cardToAccounts.end()) {
        linkedAccounts = cardToAccounts[cardNumber];  // Retrieve associated account numbers
    } else {
        std::cout << "No accounts linked to this card.\n";
    }

    return linkedAccounts;
}


Account* BankAPI::getAccount(const std::string& accountNumber) {
    if (accounts.find(accountNumber) != accounts.end()) {
        return &accounts[accountNumber];
    }
    return nullptr;
}
