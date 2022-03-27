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
    private:
        Identifier m_identifier;
    };
}

#endif // CARD_H
