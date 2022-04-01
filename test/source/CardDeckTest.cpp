// Test Includes
#include "CardDeckTest.h"

// Project Includes
#include "CardDeck.h"

TEST(DrawPiquetDeck, CardDeckTest)
{
    Card::Deck deck = Card::Deck(Card::DeckType(Card::SuitConstants::AllSuits, Card::PipConstants::PiquetPips));
    int intendedDeckSize = 32;

    for (int i = 0; i < intendedDeckSize; i++)
    {
        deck.draw();
    }

    ASSERT_EQ(deck.size(), 0);
}

TEST(DrawFullDeck, CardDeckTest)
{
    Card::Deck deck = Card::Deck(Card::DeckType(Card::SuitConstants::AllSuits , Card::PipConstants::StandardPips));
    int intendedDeckSize = 52;

    for (int i = 0; i < intendedDeckSize; i++)
    {
        deck.draw();
    }

    ASSERT_EQ(deck.size(), 0);
}

TEST(DrawCustomDeck, CardDeckTest)
{
    std::vector<Card::Suit> suits{ Card::Suit::Diamond, Card::Suit::Heart };
    std::vector<Card::Pip> pips{ Card::Pip::Ace, Card::Pip::Two };
    Card::Deck deck = Card::Deck(Card::DeckType(suits, pips));
    int intendedDeckSize = 4;

    for (int i = 0; i < intendedDeckSize; i++)
    {
        deck.draw();
    }

    ASSERT_EQ(deck.size(), 0);
}
