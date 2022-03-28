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
                            bool gameProceedButtonActive) :
        m_diamondPosition(diamondPosition),
        m_heartPosition(heartPosition),
        m_spadePosition(spadePosition),
        m_clubPosition(clubPosition),
        m_deck(deck),
        m_drawnCard(drawnCard),
        m_hurdles(hurdles),
        m_gameDrawButtonActive(gameDrawButtonActive),
        m_gameProceedButtonActive(gameProceedButtonActive) {}

    short getDiamondPosition() { return this->m_diamondPosition; }
    short getHeartPosition() { return this->m_heartPosition; }
    short getSpadePosition() { return this->m_spadePosition; }
    short getClubPosition() { return this->m_clubPosition; }
    Card::Deck getDeck() { return this->m_deck; }
    Card::Card getDrawnCard() { return this->m_drawnCard; }
    std::vector<std::pair<Card::Card, bool>> getHurdles() { return this->m_hurdles; }
    bool getGameDrawButtonActive() { return this->m_gameDrawButtonActive; }
    bool getGameProceedButtonActive() { return this->m_gameProceedButtonActive; }

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
};

#endif // DRAW_CARD_USE_CASE_H
