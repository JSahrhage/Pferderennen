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

        std::string getAcronym();
        Card::Suit getSuit() { return this->m_identifier.getSuit(); }
        Card::Pip getPip() { return this->m_identifier.getPip(); }

    private:
        Identifier m_identifier;
    };
}

#endif // CARD_H
