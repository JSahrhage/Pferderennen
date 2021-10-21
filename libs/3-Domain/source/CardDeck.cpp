#include "CardDeck.h"

Card::Deck::Deck(const DeckType& deckType) : m_deckType(deckType)
{
    fillDeck();
}

void Card::Deck::fillDeck()
{
    for (const auto& cardSuit : m_deckType.getSuits())
    {
        addPips(cardSuit);
    }
}

void Card::Deck::addPips(const Suit& suit)
{
    for (const auto& pip : m_deckType.getPips())
    {
        Card card = Card(Identifier(suit, pip));
        m_deck.push_back(card);
    }
}
