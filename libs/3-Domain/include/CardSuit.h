#ifndef CARD_SUIT_H
#define CARD_SUIT_H

#include <vector>

namespace Card
{
    enum class Suit { Clubs, Diamonds, Hearts, Spades };

    const std::vector<Suit> allSuits = { Suit::Clubs, Suit::Diamonds, Suit::Hearts, Suit::Spades };
}

#endif // CARD_SUIT_H
