#ifndef INITIALIZE_GAME_USE_CASE_H
#define INITIALIZE_GAME_USE_CASE_H

// Project Includes
#include "Bet.h"
#include "CardDeck.h"
#include "Card.h"

class InitializeGameUseCaseResponse
{
public:
    InitializeGameUseCaseResponse(std::vector<Bet> bets, Card::Deck deck, std::vector<std::pair<Card::Card, bool>> hurdles) : m_bets(bets), m_deck(deck), m_hurdles(hurdles) {}

    std::vector<Bet> getBets() { return this->m_bets; }
    Card::Deck getDeck() { return this->m_deck; }
    std::vector<std::pair<Card::Card, bool>> getHurdles() { return this->m_hurdles; }

private:
    std::vector<Bet> m_bets;
    Card::Deck m_deck;
    std::vector<std::pair<Card::Card, bool>> m_hurdles;
};

class InitializeGameUseCase
{
public:
    static InitializeGameUseCaseResponse execute(const std::vector<std::tuple<std::string, std::string, int>>& bets);

private:
    InitializeGameUseCase() {}
};

#endif // INITIALIZE_GAME_USE_CASE_H
