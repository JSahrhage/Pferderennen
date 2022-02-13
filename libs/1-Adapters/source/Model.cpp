// C++ Library Includes

// Project Includes
#include "Model.h"

Model::Model(const Game::View& gameView, const Game::Mode& gameMode)
{
    this->setGameView(gameView);
    this->setGameMode(gameMode);
}

void Model::setGameView(const Game::View& gameView)
{
    this->m_gameView = gameView;
}

Game::View Model::getGameView()
{
    return this->m_gameView;
}

void Model::setGameMode(const Game::Mode& gameMode)
{
    this->m_gameMode = gameMode;
}

Game::Mode Model::getGameMode()
{
    return this->m_gameMode;
}
