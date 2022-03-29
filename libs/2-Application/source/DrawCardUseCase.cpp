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
        return DrawCardUseCaseResponse(diamondPosition, heartPosition, spadePosition, clubPosition, deck, lastDrawnCard, hurdles, false, true, Card::Suit::Diamond);
    }
    Card::Card drawnCard = deck.draw();

    switch (drawnCard.getSuit())
    {
        case Card::Suit::Diamond:
        {
            if (dragCard(diamondPosition, 1))
            {
                return DrawCardUseCaseResponse(diamondPosition, heartPosition, spadePosition, clubPosition, deck, drawnCard, hurdles, false, true, Card::Suit::Diamond);
            }
            break;
        }
        case Card::Suit::Heart:
        {
            if (dragCard(heartPosition, 1))
            {
                return DrawCardUseCaseResponse(diamondPosition, heartPosition, spadePosition, clubPosition, deck, drawnCard, hurdles, false, true, Card::Suit::Heart);
            }
            break;
        }
        case Card::Suit::Spade:
        {
            if (dragCard(spadePosition, 1))
            {
                return DrawCardUseCaseResponse(diamondPosition, heartPosition, spadePosition, clubPosition, deck, drawnCard, hurdles, false, true, Card::Suit::Spade);
            }
            break;
        }
        case Card::Suit::Club:
        {
            if (dragCard(clubPosition, 1))
            {
                return DrawCardUseCaseResponse(diamondPosition, heartPosition, spadePosition, clubPosition, deck, drawnCard, hurdles, false, true, Card::Suit::Club);
            }
            break;
        }
        default:
        {
            break;
        }
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
                if (dragCard(diamondPosition, dragNumber))
                {
                    return DrawCardUseCaseResponse(diamondPosition, heartPosition, spadePosition, clubPosition, deck, drawnCard, hurdles, false, true, Card::Suit::Diamond);
                }
                break;
            }
            case Card::Suit::Heart:
            {
                if (dragCard(heartPosition, dragNumber))
                {
                    return DrawCardUseCaseResponse(diamondPosition, heartPosition, spadePosition, clubPosition, deck, drawnCard, hurdles, false, true, Card::Suit::Heart);
                }
                break;
            }
            case Card::Suit::Spade:
            {
                if (dragCard(spadePosition, dragNumber))
                {
                    return DrawCardUseCaseResponse(diamondPosition, heartPosition, spadePosition, clubPosition, deck, drawnCard, hurdles, false, true, Card::Suit::Spade);
                }
                break;
            }
            case Card::Suit::Club:
            {
                if (dragCard(clubPosition, dragNumber))
                {
                    return DrawCardUseCaseResponse(diamondPosition, heartPosition, spadePosition, clubPosition, deck, drawnCard, hurdles, false, true, Card::Suit::Club);
                }
                break;
            }
            default:
            {
                break;
            }
        }
    }

    return DrawCardUseCaseResponse(diamondPosition, heartPosition, spadePosition, clubPosition, deck, drawnCard, hurdles, true, false, Card::Suit::Diamond);
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
