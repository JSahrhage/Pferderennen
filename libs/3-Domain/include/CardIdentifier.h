#ifndef CARD_IDENTIFIER_H
#define CARD_IDENTIFIER_H

#include "CardSuit.h"
#include "CardPip.h"

namespace Card
{
    class Identifier
    {
    public:
        Identifier(const Suit& suit, const Pip& pip) : m_suit(suit), m_pip(pip) {}

    private:
        const Suit m_suit;
        const Pip m_pip;
    };
}

#endif // CARD_IDENTIFIER_H
