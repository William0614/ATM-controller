#include "../include/card.h"

Card::Card(const std::string& cardNumber) : cardNumber(cardNumber) {}

std::string Card::getCardNumber() const {
    return cardNumber;
}
