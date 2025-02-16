#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
private:
    std::string cardNumber;

public:
    Card(std::string cardNum);
    std::string getCardNumber() const;
};

#endif
