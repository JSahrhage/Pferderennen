#ifndef ENTER_PLAYER_USE_CASE_H
#define ENTER_PLAYER_USE_CASE_H

// Project Includes
#include "Bet.h"

class EnterPlayerUseCaseResponse
{
public:
    EnterPlayerUseCaseResponse(std::vector<Player> player, bool enoughPlayer) : m_player(player), m_enoughPlayer(enoughPlayer) {}

    std::vector<Player> getPlayer() { return this->m_player; }
    bool getEnoughPlayer() { return this->m_enoughPlayer; }

private:
    std::vector<Player> m_player;
    bool m_enoughPlayer;
};

class EnterPlayerUseCase
{
public:
    static EnterPlayerUseCaseResponse execute(const std::vector<std::string>& player);

private:
    EnterPlayerUseCase() {}
};

#endif // ENTER_PLAYER_USE_CASE_H
