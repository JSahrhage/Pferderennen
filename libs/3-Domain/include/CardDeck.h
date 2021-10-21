#ifndef CARD_DECK_H
#define CARD_DECK_H

#include <vector>

#include "Card.h"
#include "CardDeckType.h"

class CardDeck
{
public:
    CardDeck(const CardDeckType& cardDeckType);
    CardDeck() = delete;

private:
    void fillDeck();
    void addCardPips(const CardSuit& cardSuit);

private:
    std::vector<Card> m_cardDeck;
    const CardDeckType m_cardDeckType;
};

#endif // CARD_DECK_H
