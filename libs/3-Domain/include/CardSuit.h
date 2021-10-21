#ifndef CARD_SUIT_H
#define CARD_SUIT_H

#include <vector>

enum class CardSuit { Clubs, Diamonds, Hearts, Spades };

std::vector<CardSuit> allCardSuits = { CardSuit::Clubs, CardSuit::Diamonds, CardSuit::Hearts, CardSuit::Spades };

#endif // CARD_SUIT_H
