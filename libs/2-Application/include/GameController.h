#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

// C++ Library Includes
#include <memory>

// Project Includes
#include "GameModeSelector.h"

class GameController
{
public:
    GameController(std::shared_ptr<GameModeSelector> gameModeSelector);

    void startGame();
    void draw();

private:
    std::shared_ptr<GameModeSelector> m_gameModeSelector;
};

#endif // GAME_CONTROLLER_H
