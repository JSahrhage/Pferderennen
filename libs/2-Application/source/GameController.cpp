// Project Includes
#include "GameController.h"

#include <iostream>

GameController::GameController(std::shared_ptr<GameModeSelector> gameModeSelector) : m_gameModeSelector(gameModeSelector)
{
    if (!gameModeSelector)
    {
        throw std::exception("Null depedency");
    }
    // Load Configs
    startGame();
}

void GameController::startGame()
{
    m_gameModeSelector->getGameModeSelection();
}
