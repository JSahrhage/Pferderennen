#ifndef CARD_DECK_H
#define CARD_DECK_H

// C++ Library Includes
#include <vector>

// Project Includes
#include "Card.h"
#include "CardDeckType.h"

namespace Card
{
    class Deck
    {
    public:
        Deck(const DeckType& deckType);

        void print();
        void shuffle();
        Card draw();
    private:
        void fillDeck();
        void addPips(const Suit& suit);

        std::vector<Card> m_deck;
        DeckType m_deckType;
    };
}
#endif // CARD_DECK_H
