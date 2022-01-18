#ifndef CARD_H
#define CARD_H

// Project Includes
#include "CardIdentifier.h"

namespace Card
{
    class Card
    {
    public:
        Card(const Identifier& identifier) : m_identifier(identifier) {}

        void print() const;
    private:
        Identifier m_identifier;
    };
}

#endif // CARD_H
