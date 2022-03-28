// Project Includes
#include "InitializeGameUseCase.h"

InitializeGameUseCaseResponse InitializeGameUseCase::execute()
{
    Card::Deck deck = Card::Deck(Card::DeckType(Card::SuitConstants::AllSuits, Card::PipConstants::PiquetPips));
    deck.shuffle();
    std::vector<std::pair<Card::Card, bool>> hurdles;
    for (int i = 0; i < 5; i++)
    {
        hurdles.insert(hurdles.begin(), std::make_pair(deck.draw(), true));
    }

    return InitializeGameUseCaseResponse(deck, hurdles);
}