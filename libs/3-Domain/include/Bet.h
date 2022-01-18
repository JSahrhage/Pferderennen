#ifndef BET_H
#define BET_H

// Project Includes
#include "CardSuit.h"
#include "Player.h"

class Bet
{
public:
    Bet(const Player& player, const Card::Suit& suit, const int& sips) : m_player(player), m_suit(suit), m_sips(sips) {}

    void doubleSips();
    void halveSips();
    Player getPlayer() { return this->m_player; }
    Card::Suit getSuit() { return this->m_suit; }
    int getSips() { return this->m_sips; }

private:
    Player m_player;
    Card::Suit m_suit;
    int m_sips;
};

#endif // BET_H
