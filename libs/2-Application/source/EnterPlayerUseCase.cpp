// Project Includes
#include "EnterPlayerUseCase.h"

EnterPlayerUseCaseResponse EnterPlayerUseCase::execute(const std::vector<std::string>& player)
{
    std::vector<Player> castedPlayer;
    for (const auto& player : player)
    {
        if (player.empty())
        {
            continue;
        }

        castedPlayer.push_back(Player(player));
    }

    bool enoughPlayer = true;
    if (castedPlayer.size() < 2)
    {
        enoughPlayer = false;
    }

    return EnterPlayerUseCaseResponse(castedPlayer, enoughPlayer);
}
