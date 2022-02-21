#ifndef MODEL_H
#define MODEL_H

// C++ Library Includes
#include <string>

// Project Includes
#include "GameView.h"
#include "GameMode.h"

class Model {
public:
    Model() {}
    Model(const Game::View& gameView, const Game::Mode& gameMode);

    void setGameView(const Game::View& gameView);
    Game::View getGameView();

    void setGameMode(const Game::Mode& gameMode);
    Game::Mode getGameMode();

private:
    Game::View m_gameView = Game::View::SelectGameMode;
    Game::Mode m_gameMode = Game::Mode::Normal;
};

#endif // MODEL_H
