#ifndef CARD_H
#define CARD_H

#include "CardIdentifier.h"

class Card
{
public:
    Card(const CardIdentifier& cardIdentifier) : m_cardIdentifier(cardIdentifier) {}

private:
    const CardIdentifier m_cardIdentifier;
};

#endif // CARD_H
