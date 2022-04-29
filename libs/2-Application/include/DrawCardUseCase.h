#ifndef DRAW_CARD_USE_CASE_H
#define DRAW_CARD_USE_CASE_H

// C++ Library Includes
#include <vector>
#include <memory>

// Project Includes
#include "Card.h"
#include "CardDeck.h"

class DrawCardUseCaseResponse
{
public:
    DrawCardUseCaseResponse(short diamondPosition,
                            short heartPosition,
                            short spadePosition,
                            short clubPosition,
                            Card::Deck deck,
                            Card::Card drawnCard,
                            std::vector<std::pair<Card::Card, bool>> hurdles,
                            bool gameDrawButtonActive,
                            bool gameProceedButtonActive,
                            Card::Suit victoriousSuit) :
        m_diamondPosition(diamondPosition),
        m_heartPosition(heartPosition),
        m_spadePosition(spadePosition),
        m_clubPosition(clubPosition),
        m_deck(deck),
        m_drawnCard(drawnCard),
        m_hurdles(hurdles),
        m_gameDrawButtonActive(gameDrawButtonActive),
        m_gameProceedButtonActive(gameProceedButtonActive),
        m_victoriousSuit(victoriousSuit) {}

    short getDiamondPosition() { return this->m_diamondPosition; }
    short getHeartPosition() { return this->m_heartPosition; }
    short getSpadePosition() { return this->m_spadePosition; }
    short getClubPosition() { return this->m_clubPosition; }
    Card::Deck getDeck() { return this->m_deck; }
    Card::Card getDrawnCard() { return this->m_drawnCard; }
    std::vector<std::pair<Card::Card, bool>> getHurdles() { return this->m_hurdles; }
    bool getGameDrawButtonActive() { return this->m_gameDrawButtonActive; }
    bool getGameProceedButtonActive() { return this->m_gameProceedButtonActive; }
    Card::Suit getVictoriousSuit() { return this->m_victoriousSuit; }

private:
    short m_diamondPosition;
    short m_heartPosition;
    short m_spadePosition;
    short m_clubPosition;
    Card::Deck m_deck;
    Card::Card m_drawnCard;
    std::vector<std::pair<Card::Card, bool>> m_hurdles;
    bool m_gameDrawButtonActive;
    bool m_gameProceedButtonActive;
    Card::Suit m_victoriousSuit;
};

class DrawCardUseCase
{
public:
    static DrawCardUseCaseResponse execute(short diamondPosition,
                                           short heartPosition,
                                           short spadePosition,
                                           short clubPosition,
                                           Card::Deck deck,
                                           Card::Card lastDrawnCard,
                                           std::vector<std::pair<Card::Card, bool>> hurdles);

private:
    DrawCardUseCase() {}

    static bool dragCard(short& cardPosition, const short& steps);

    static std::pair<bool, DrawCardUseCaseResponse> checkWinAfterInitialDrag(short& diamondPosition,
                                                                             short& heartPosition,
                                                                             short& spadePosition,
                                                                             short& clubPosition,
                                                                             const Card::Deck& deck,
                                                                             Card::Card& drawnCard,
                                                                             const std::vector<std::pair<Card::Card, bool>>& hurdles);

    static int getFirstCoveredHurdleIndex(const std::vector<std::pair<Card::Card, bool>>& hurdles);

    static bool doesHurdleNeedsToBeRevealed(const short& diamondPosition,
                                            const short& heartPosition,
                                            const short& spadePosition,
                                            const short& clubPosition, 
                                            const int& firstCoveredHurdleIndex);

    static int getNumberOfDragsOfHurdle(const int& firstCoveredHurdleIndex,
                                        std::vector<std::pair<Card::Card, bool>>& hurdles);

    static std::pair<bool, DrawCardUseCaseResponse> checkWinAfterHurdleDrag(short& diamondPosition,
                                                                            short& heartPosition,
                                                                            short& spadePosition,
                                                                            short& clubPosition,
                                                                            const Card::Deck& deck,
                                                                            Card::Card& drawnCard,
                                                                            std::vector<std::pair<Card::Card, bool>>& hurdles,
                                                                            const int& dragNumber,
                                                                            const int& firstCoveredHurdleIndex);
};

#endif // DRAW_CARD_USE_CASE_H
