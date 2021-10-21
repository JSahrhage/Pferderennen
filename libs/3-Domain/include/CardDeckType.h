#ifndef CARD_DECK_TYPE_H
#define CARD_DECK_TYPE_H

#include <vector>

#include "CardSuit.h"
#include "CardPip.h"

class CardDeckType
{
public:
    CardDeckType(const std::vector<CardSuit> cardSuits, const std::vector<CardPip> cardPips) : m_cardSuits(cardSuits), m_cardPips(cardPips) {}
    const std::vector<CardSuit> getCardSuits() const { return this->m_cardSuits; }
    const std::vector<CardPip> getCardPips() const { return this->m_cardPips; }

private:
    const std::vector<CardSuit> m_cardSuits;
    const std::vector<CardPip> m_cardPips;
};

#endif // CARD_DECK_TYPE_H
