// Project Includes
#include "DrawCardUseCase.h"

DrawCardUseCaseResponse DrawCardUseCase::execute(short diamondPosition,
                                                 short heartPosition,
                                                 short spadePosition,
                                                 short clubPosition,
                                                 Card::Deck deck,
                                                 Card::Card lastDrawnCard,
                                                 std::vector<std::pair<Card::Card, bool>> hurdles)
{
    if (deck.size() == 0)
    {
        return DrawCardUseCaseResponse(diamondPosition, heartPosition, spadePosition, clubPosition, deck, lastDrawnCard, hurdles, false, true);
    }
    Card::Card drawnCard = deck.draw();

    bool isOver = false;
    switch (drawnCard.getSuit())
    {
        case Card::Suit::Diamond:
        {
            isOver = dragCard(diamondPosition, 1);
            break;
        }
        case Card::Suit::Heart:
        {
            isOver = dragCard(heartPosition, 1);
            break;
        }
        case Card::Suit::Spade:
        {
            isOver = dragCard(spadePosition, 1);
            break;
        }
        case Card::Suit::Club:
        {
            isOver = dragCard(clubPosition, 1);
            break;
        }
        default:
        {
            break;
        }
    }

    if (isOver)
    {
        return DrawCardUseCaseResponse(diamondPosition, heartPosition, spadePosition, clubPosition, deck, drawnCard, hurdles, false, true);
    }

    int firstCoveredHurdleIndex = 0;
    for (const auto& [card, isRevealed] : hurdles)
    {
        if (!isRevealed)
        {
            break;
        }

        firstCoveredHurdleIndex++;
    }

    bool isOverAfterHurdles = false;
    if (diamondPosition >= firstCoveredHurdleIndex + 1 &&
        heartPosition >= firstCoveredHurdleIndex + 1 &&
        spadePosition >= firstCoveredHurdleIndex + 1 &&
        clubPosition >= firstCoveredHurdleIndex + 1)
    {
        hurdles.at(firstCoveredHurdleIndex).second = true;

        short dragNumber = 0;
        switch (hurdles.at(firstCoveredHurdleIndex).first.getPip())
        {
            case Card::Pip::Seven:
            {
                dragNumber = -1;
                break;
            }
            case Card::Pip::Eight:
            {
                dragNumber = -1;
                break;
            }
            case Card::Pip::Nine:
            {
                dragNumber = -1;
                break;
            }
            case Card::Pip::Ten:
            {
                dragNumber = 1;
                break;
            }
            case Card::Pip::Jack:
            {
                dragNumber = 1;
                break;
            }
            case Card::Pip::Queen:
            {
                dragNumber = 1;
                break;
            }
            case Card::Pip::King:
            {
                dragNumber = 2;
                break;
            }
            default:
            {
                break;
            }
        }

        switch (hurdles.at(firstCoveredHurdleIndex).first.getSuit())
        {
            case Card::Suit::Diamond:
            {
                isOverAfterHurdles = dragCard(diamondPosition, dragNumber);
                break;
            }
            case Card::Suit::Heart:
            {
                isOverAfterHurdles = dragCard(heartPosition, dragNumber);
                break;
            }
            case Card::Suit::Spade:
            {
                isOverAfterHurdles = dragCard(spadePosition, dragNumber);
                break;
            }
            case Card::Suit::Club:
            {
                isOverAfterHurdles = dragCard(clubPosition, dragNumber);
                break;
            }
            default:
            {
                break;
            }
        }

        if (isOverAfterHurdles)
        {
            return DrawCardUseCaseResponse(diamondPosition, heartPosition, spadePosition, clubPosition, deck, drawnCard, hurdles, false, true);
        }
    }

    return DrawCardUseCaseResponse(diamondPosition, heartPosition, spadePosition, clubPosition, deck, drawnCard, hurdles, true, false);
}

bool DrawCardUseCase::dragCard(short& cardPosition, const short& steps)
{
    cardPosition += steps;

    if (cardPosition > 6)
    {
        cardPosition = 6;
    }
    else if (cardPosition < 0)
    {
        cardPosition = 0;
    }

    if (cardPosition == 6)
    {
        return true;
    }

    return false;
}
