#ifndef CARD_DECK_H
#define CARD_DECK_H

#include <vector>

#include "Card.h"
#include "CardDeckType.h"

namespace Card
{
    class Deck
    {
    public:
        Deck(const DeckType& deckType);

    private:
        void fillDeck();
        void addPips(const Suit& suit);

    private:
        std::vector<Card> m_deck;
        const DeckType m_deckType;
    };
}
#endif // CARD_DECK_H
