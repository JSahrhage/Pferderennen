#ifndef CARD_IDENTIFIER_H
#define CARD_IDENTIFIER_H

#include "CardSuit.h"
#include "CardPip.h"

class CardIdentifier
{
public:
    CardIdentifier(const CardSuit& cardSuit, const CardPip& cardPip) : m_cardSuit(cardSuit), m_cardPip(cardPip) {}

private:
    const CardSuit m_cardSuit;
    const CardPip m_cardPip;
};

#endif // CARD_IDENTIFIER_H
