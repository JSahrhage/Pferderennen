// C++ Library Includes

// Project Includes
#include "Model.h"

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

void Model::setClubsPosition(const short& clubsPosition)
{

}

short Model::getClubsPosition()
{

}

void Model::setDiamondsPosition(const short& clubsPosition)
{

}

short Model::getDiamondsPosition()
{

}

void Model::setHeartsPosition(const short& clubsPosition)
{

}

short Model::getHeartsPosition()
{

}

void Model::setSpadesPosition(const short& clubsPosition)
{

}

short Model::getSpadesPosition()
{

}
