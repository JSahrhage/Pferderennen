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
        Deck(const std::vector<Card>& deck);

        int size();
        Card draw();
        std::vector<Card> toCardVector();

    private:
        std::vector<Card> m_deck;
    };
}
#endif // CARD_DECK_H
