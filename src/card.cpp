#include "../include/card.h"

Card::Card(std::string cardNum) : cardNumber(cardNum) {}

std::string Card::getCardNumber() const {
    return cardNumber;
}
