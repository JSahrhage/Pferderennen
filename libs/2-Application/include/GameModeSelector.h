#ifndef GAME_MODE_SELECTOR_H
#define GAME_MODE_SELECTOR_H

// Project Includes
#include "GameMode.h"

class GameModeSelector
{
public:
    virtual Game::Mode getGameModeSelection() = 0;
};

#endif // GAME_MODE_SELECTOR_H
