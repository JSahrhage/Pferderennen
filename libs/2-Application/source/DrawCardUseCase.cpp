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

    std::pair<bool, DrawCardUseCaseResponse> gameOverAfterInitialDrag = checkWinAfterInitialDrag(diamondPosition,
                                                                                                 heartPosition,
                                                                                                 spadePosition,
                                                                                                 clubPosition,
                                                                                                 deck,
                                                                                                 drawnCard,
                                                                                                 hurdles);

    if (gameOverAfterInitialDrag.first)
    {
        return gameOverAfterInitialDrag.second;
    }

    int firstCoveredHurdleIndex = getFirstCoveredHurdleIndex(hurdles);

    bool hurdleNeedsToBeRevealed = doesHurdleNeedsToBeRevealed(diamondPosition,
                                                               heartPosition,
                                                               spadePosition,
                                                               clubPosition,
                                                               firstCoveredHurdleIndex);

    if (hurdleNeedsToBeRevealed)
    {
        int dragNumber = getNumberOfDragsOfHurdle(firstCoveredHurdleIndex, hurdles);
        std::pair<bool, DrawCardUseCaseResponse> gameOverAfterHurdleDrag = checkWinAfterHurdleDrag(diamondPosition,
                                                                                                   heartPosition,
                                                                                                   spadePosition,
                                                                                                   clubPosition,
                                                                                                   deck,
                                                                                                   drawnCard,
                                                                                                   hurdles,
                                                                                                   dragNumber,
                                                                                                   firstCoveredHurdleIndex);
        if (gameOverAfterHurdleDrag.first)
        {
            return gameOverAfterHurdleDrag.second;
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

std::pair<bool, DrawCardUseCaseResponse> DrawCardUseCase::checkWinAfterInitialDrag(short& diamondPosition,
                                                                                   short& heartPosition,
                                                                                   short& spadePosition,
                                                                                   short& clubPosition,
                                                                                   const Card::Deck& deck,
                                                                                   Card::Card& drawnCard,
                                                                                   const std::vector<std::pair<Card::Card, bool>>& hurdles)
{
    bool gameOver = false;
    Card::Suit victoriousSuit = Card::Suit::Diamond;
    switch (drawnCard.getSuit())
    {
        case Card::Suit::Diamond:
        {
            gameOver = dragCard(diamondPosition, 1);
            victoriousSuit = Card::Suit::Diamond;
            break;
        }
        case Card::Suit::Heart:
        {
            gameOver = dragCard(heartPosition, 1);
            victoriousSuit = Card::Suit::Heart;
            break;
        }
        case Card::Suit::Spade:
        {
            gameOver = dragCard(spadePosition, 1);
            victoriousSuit = Card::Suit::Spade;
            break;
        }
        case Card::Suit::Club:
        {
            gameOver = dragCard(clubPosition, 1);
            victoriousSuit = Card::Suit::Club;
            break;
        }
        default:
        {
            break;
        }
    }

    return std::make_pair(gameOver, DrawCardUseCaseResponse(diamondPosition, heartPosition, spadePosition, clubPosition, deck, drawnCard, hurdles, false, true, victoriousSuit));
}

int DrawCardUseCase::getFirstCoveredHurdleIndex(const std::vector<std::pair<Card::Card, bool>>& hurdles)
{
    int firstCoveredHurdleIndex = 0;
    for (const auto& [card, isRevealed] : hurdles)
    {
        if (!isRevealed)
        {
            break;
        }

        firstCoveredHurdleIndex++;
    }
    
    return firstCoveredHurdleIndex;
}

bool DrawCardUseCase::doesHurdleNeedsToBeRevealed(const short& diamondPosition,
                                                  const short& heartPosition,
                                                  const short& spadePosition,
                                                  const short& clubPosition,
                                                  const int& firstCoveredHurdleIndex)
{
    if (diamondPosition >= firstCoveredHurdleIndex + 1 &&
        heartPosition >= firstCoveredHurdleIndex + 1 &&
        spadePosition >= firstCoveredHurdleIndex + 1 &&
        clubPosition >= firstCoveredHurdleIndex + 1)
    {
        return true;
    }

    return false;
}

int DrawCardUseCase::getNumberOfDragsOfHurdle(const int& firstCoveredHurdleIndex,
                                              std::vector<std::pair<Card::Card, bool>>& hurdles)
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

    return dragNumber;
}

std::pair<bool, DrawCardUseCaseResponse> DrawCardUseCase::checkWinAfterHurdleDrag(short& diamondPosition,
                                                                                  short& heartPosition,
                                                                                  short& spadePosition,
                                                                                  short& clubPosition,
                                                                                  const Card::Deck& deck,
                                                                                  Card::Card& drawnCard,
                                                                                  std::vector<std::pair<Card::Card, bool>>& hurdles,
                                                                                  const int& dragNumber,
                                                                                  const int& firstCoveredHurdleIndex)
{
    bool gameOver = false;
    Card::Suit victoriousSuit = Card::Suit::Diamond;
    switch (hurdles.at(firstCoveredHurdleIndex).first.getSuit())
    {
        case Card::Suit::Diamond:
        {
            gameOver = dragCard(diamondPosition, dragNumber);
            victoriousSuit = Card::Suit::Diamond;
            break;
        }
        case Card::Suit::Heart:
        {
            gameOver = dragCard(heartPosition, dragNumber);
            victoriousSuit = Card::Suit::Heart;
            break;
        }
        case Card::Suit::Spade:
        {
            gameOver = dragCard(spadePosition, dragNumber);
            victoriousSuit = Card::Suit::Spade;
            break;
        }
        case Card::Suit::Club:
        {
            gameOver = dragCard(clubPosition, dragNumber);
            victoriousSuit = Card::Suit::Club;
            break;
        }
        default:
        {
            break;
        }
    }

    return std::make_pair(gameOver, DrawCardUseCaseResponse(diamondPosition, heartPosition, spadePosition, clubPosition, deck, drawnCard, hurdles, false, true, victoriousSuit));
}
