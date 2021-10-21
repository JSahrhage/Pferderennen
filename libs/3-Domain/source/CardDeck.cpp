#include "CardDeck.h"

CardDeck::CardDeck(const CardDeckType& cardDeckType) : m_cardDeckType(cardDeckType)
{
    fillDeck();
}

void CardDeck::fillDeck()
{
    for (const CardSuit& cardSuit : m_cardDeckType.getCardSuits())
    {
        addCardPips(cardSuit);
    }
}

void CardDeck::addCardPips(const CardSuit& cardSuit)
{
    for (const CardPip& cardPip : m_cardDeckType.getCardPips())
    {
        Card card(CardIdentifier(cardSuit, cardPip));
        m_cardDeck.push_back(card);
    }
}
