// C++ Library Includes
#include <algorithm>
#include <random>
#include <chrono>

// Project Includes
#include "ShuffleDeckUseCase.h"

ShuffleDeckUseCaseResponse ShuffleDeckUseCase::execute(Card::Deck& deck)
{
    std::vector<Card::Card> deckAsCardVector = deck.toCardVector();
    std::random_device randomDevice = std::random_device{};
    std::default_random_engine defaultRandomEngine = std::default_random_engine{ randomDevice() };
    std::shuffle(std::begin(deckAsCardVector), std::end(deckAsCardVector), defaultRandomEngine);

    return ShuffleDeckUseCaseResponse(deckAsCardVector);
}
