#ifndef CARD_IDENTIFIER_H
#define CARD_IDENTIFIER_H

// Project Includes
#include "CardSuit.h"
#include "CardPip.h"

namespace Card
{
    class Identifier
    {
    public:
        Identifier(const Suit& suit, const Pip& pip) : m_suit(suit), m_pip(pip) {}

        const Suit& getSuit() const { return this->m_suit; }
        const Pip& getPip() const { return this->m_pip; }
    private:
        Suit m_suit;
        Pip m_pip;
    };
}

#endif // CARD_IDENTIFIER_H
