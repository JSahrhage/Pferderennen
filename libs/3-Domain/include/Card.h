#ifndef CARD_H
#define CARD_H

#include "CardIdentifier.h"

namespace Card
{
    class Card
    {
    public:
        Card(const Identifier& identifier) : m_identifier(identifier) {}

    private:
        const Identifier m_identifier;
    };
}

#endif // CARD_H
