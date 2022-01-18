#ifndef CARD_SUIT_H
#define CARD_SUIT_H

// C++ Library Includes
#include <vector>

namespace Card
{
    enum class Suit { Clubs, Diamonds, Hearts, Spades };

    namespace SuitConstants
    {
        const std::vector<Suit> AllSuits = { Suit::Clubs, Suit::Diamonds, Suit::Hearts, Suit::Spades };
    }
}

#endif // CARD_SUIT_H
