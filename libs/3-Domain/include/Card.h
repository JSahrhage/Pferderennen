#ifndef CARD_H
#define CARD_H

// C++ Library Includes
#include <string>

// Project Includes
#include "CardIdentifier.h"

// ValueObject

namespace Card
{
    class Card
    {
    public:
        Card(const Identifier& identifier) : m_identifier(identifier) {}

        inline friend bool operator==(Card& lhs, Card& rhs) { return ((lhs.getSuit() == rhs.getSuit()) && (lhs.getPip() == rhs.getPip())); }

        Card::Suit getSuit() { return this->m_identifier.getSuit(); }
        Card::Pip getPip() { return this->m_identifier.getPip(); }

    private:
        Identifier m_identifier;
    };
}

#endif // CARD_H
