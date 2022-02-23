#ifndef MODEL_H
#define MODEL_H

// C++ Library Includes
#include <string>
#include <map>

// Project Includes
#include "GameView.h"
#include "GameMode.h"
#include "CardDeck.h"
#include "Card.h"

class Model {
public:
    void setGameView(const Game::View& gameView) { this->m_gameView = gameView; }
    Game::View getGameView() { return this->m_gameView; }

    void setGameMode(const Game::Mode& gameMode) { this->m_gameMode = gameMode; }
    Game::Mode getGameMode() { return this->m_gameMode; }

    void setClubsPosition(const short& clubsPosition) { this->m_clubsPosition = clubsPosition; }
    short getClubsPosition() { return this->m_clubsPosition; }
        
    void setDiamondsPosition(const short& diamondsPosition) { this->m_diamondsPosition = diamondsPosition; }
    short getDiamondsPosition() { return this->m_diamondsPosition; }

    void setHeartsPosition(const short& heartsPosition) { this->m_heartsPosition = heartsPosition; }
    short getHeartsPosition() { return this->m_heartsPosition; }

    void setSpadesPosition(const short& spadesPosition) { this->m_spadesPosition = spadesPosition; }
    short getSpadesPosition() { return this->m_spadesPosition; }

    void setDeck(const Card::Deck& deck) { this->m_deck = deck; }
    Card::Deck getDeck() { return this->m_deck; }

private:
    // View
    Game::View m_gameView = Game::View::SelectGameMode;
    // SelectGameMode
    Game::Mode m_gameMode = Game::Mode::Normal;
    // EnterPlayer
    // PlaceBets
    // Game
    short m_clubsPosition = 0;
    short m_diamondsPosition = 0;
    short m_heartsPosition = 0;
    short m_spadesPosition = 0;
    Card::Deck m_deck = Card::Deck(Card::DeckType(Card::SuitConstants::AllSuits, Card::PipConstants::PiquetPips));
    bool m_firstCardDrawn = false;
    Card::Card m_lastDrawnCard = Card::Card(Card::Identifier(Card::Suit::Diamonds, Card::Pip::Seven));
    std::map<Card::Card, bool> m_hurdles;
    bool m_drawButtonActive = true;
    // DistributeSips
};

#endif // MODEL_H
