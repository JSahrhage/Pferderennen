// Project Includes
#include "DrawCardUseCase.h"

DrawCardUseCaseResponse DrawCardUseCase::execute(short diamondPosition,
                                                 short heartPosition,
                                                 short spadePosition,
                                                 short clubPosition,
                                                 Card::Deck deck,
                                                 std::vector<std::pair<Card::Card, bool>> hurdles)
{
    Card::Card drawnCard = deck.draw();

    switch (drawnCard.getSuit())
    {
        case Card::Suit::Diamond:
        {
            diamondPosition++;
            break;
        }
        case Card::Suit::Heart:
        {
            heartPosition++;
            break;
        }
        case Card::Suit::Spade:
        {
            spadePosition++;
            break;
        }
        case Card::Suit::Club:
        {
            clubPosition++;
            break;
        }
        default:
        {
            break;
        }
    }

    int index = 0;
    for (const auto& [card, isRevealed] : hurdles)
    {
        if (!isRevealed)
        {
            break;
        }

        index++;
    }

    // TODO

    return DrawCardUseCaseResponse(diamondPosition, heartPosition, spadePosition, clubPosition, deck, drawnCard, hurdles, true, false);
}
