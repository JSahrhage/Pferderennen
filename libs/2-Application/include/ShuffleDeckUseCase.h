#ifndef SHUFFLE_DECK_USE_CASE_H
#define SHUFFLE_DECK_USE_CASE_H

// Project Includes
#include "CardDeck.h"

class ShuffleDeckUseCaseResponse
{
public:
    ShuffleDeckUseCaseResponse(Card::Deck deck) : m_deck(deck) {}

    Card::Deck getDeck() { return this->m_deck; }

private:
    Card::Deck m_deck;
};

class ShuffleDeckUseCase
{
public:
    static ShuffleDeckUseCaseResponse execute(Card::Deck& deck);

private:
    ShuffleDeckUseCase() {}
};

#endif // SHUFFLE_DECK_USE_CASE_H
