#ifndef CARD_SUIT_H
#define CARD_SUIT_H

// C++ Library Includes
#include <vector>

namespace Card
{
    enum class Suit { Diamond, Heart, Spade, Club };

    namespace SuitConstants
    {
        const std::vector<Suit> AllSuits = { Suit::Diamond, Suit::Heart, Suit::Spade, Suit::Club };
    }
}

#endif // CARD_SUIT_H
