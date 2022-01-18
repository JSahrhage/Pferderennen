#ifndef CARD_DECK_TYPE_H
#define CARD_DECK_TYPE_H

// C++ Library Includes
#include <vector>

// Project Includes
#include "CardSuit.h"
#include "CardPip.h"

namespace Card
{
    class DeckType
    {
    public:
        DeckType(const std::vector<Suit> suits, const std::vector<Pip> pips) : m_suits(suits), m_pips(pips) {}
        const std::vector<Suit>& getSuits() const { return this->m_suits; }
        const std::vector<Pip>& getPips() const { return this->m_pips; }

    private:
        const std::vector<Suit> m_suits;
        const std::vector<Pip> m_pips;
    };
}

#endif // CARD_DECK_TYPE_H
