#ifndef INITIALIZE_GAME_USE_CASE_H
#define INITIALIZE_GAME_USE_CASE_H

// Project Includes
#include "CardDeck.h"
#include "Card.h"

class InitializeGameUseCaseResponse
{
public:
    InitializeGameUseCaseResponse(Card::Deck deck, std::vector<std::pair<Card::Card, bool>> hurdles) : m_deck(deck), m_hurdles(hurdles) {}

    Card::Deck getDeck() { return this->m_deck; }
    std::vector<std::pair<Card::Card, bool>> getHurdles() { return this->m_hurdles; }

private:
    Card::Deck m_deck;
    std::vector<std::pair<Card::Card, bool>> m_hurdles;
};

class InitializeGameUseCase
{
public:
    static InitializeGameUseCaseResponse execute();

private:
    InitializeGameUseCase() {}
};

#endif // INITIALIZE_GAME_USE_CASE_H
