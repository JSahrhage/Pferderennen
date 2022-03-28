// C++ Library Includes
#include <algorithm>
#include <random>
#include <chrono>

// Project Includes
#include "CardDeck.h"

namespace Card
{
    Deck::Deck(const DeckType& deckType) : m_deckType(deckType)
    {
        fillDeck();
    }

    void Deck::fillDeck()
    {
        for (const auto& cardSuit : m_deckType.getSuits())
        {
            addPips(cardSuit);
        }
    }

    void Deck::shuffle()
    {
        auto randomDevice = std::random_device{};
        auto defaultRandomEngine = std::default_random_engine{ randomDevice() };
        std::shuffle(std::begin(m_deck), std::end(m_deck), defaultRandomEngine);
    }

    int Deck::size()
    {
        return m_deck.size();
    }

    Card Deck::draw()
    {
        auto drawnCard = m_deck.at(0);
        m_deck.erase(m_deck.cbegin());
        return drawnCard;
    }

    void Deck::addPips(const Suit& suit)
    {
        for (const auto& pip : m_deckType.getPips())
        {
            Identifier identifier = Identifier(suit, pip);
            Card card = Card(identifier);
            m_deck.push_back(card);
        }
    }
}
