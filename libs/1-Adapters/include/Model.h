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
    void setGameView(const Game::View& gameView);
    Game::View getGameView();

    void setGameMode(const Game::Mode& gameMode);
    Game::Mode getGameMode();

    void setClubsPosition(const short& clubsPosition);
    short getClubsPosition();

    void setDiamondsPosition(const short& diamondsPosition);
    short getDiamondsPosition();

    void setHeartsPosition(const short& heartsPosition);
    short getHeartsPosition();

    void setSpadesPosition(const short& spadesPosition);
    short getSpadesPosition();

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
    Card::Deck m_deck = Card::Deck();
    bool m_firstCardDrawn = false;
    Card::Card m_lastDrawnCard = Card::Card(Card::Identifier(Card::Suit::Diamonds, Card::Pip::Seven));
    std::map<Card::Card, bool> m_hurdles;
    bool m_drawButtonActive = true;
    // DistributeSips
};

#endif // MODEL_H
