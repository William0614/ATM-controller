#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
public:
    explicit Card(const std::string& cardNumber);

    std::string getCardNumber() const;

private:
    std::string cardNumber;
};

#endif // CARD_H
