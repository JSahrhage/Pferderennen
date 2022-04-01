// C++ Library Includes
#include <algorithm>
#include <random>
#include <chrono>

// Project Includes
#include "CardDeck.h"

namespace Card
{
    Deck::Deck(const DeckType& deckType)
    {
        for (const Suit& suit : deckType.getSuits())
        {
            for (const Pip& pip : deckType.getPips())
            {
                m_deck.push_back(Card(Identifier(suit, pip)));
            }
        }
    }

    Deck::Deck(const std::vector<Card>& deck) : m_deck(deck)
    {

    }

    void Deck::shuffle()
    {
        std::random_device randomDevice = std::random_device{};
        std::default_random_engine defaultRandomEngine = std::default_random_engine{ randomDevice() };
        std::shuffle(std::begin(m_deck), std::end(m_deck), defaultRandomEngine);
    }

    int Deck::size()
    {
        return static_cast<int>(m_deck.size());
    }

    Card Deck::draw()
    {
        auto drawnCard = m_deck.at(0);
        m_deck.erase(m_deck.cbegin());
        return drawnCard;
    }
}
