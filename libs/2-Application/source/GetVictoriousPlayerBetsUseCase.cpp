// Project Includes
#include "GetVictoriousPlayerBetsUseCase.h"

GetVictoriousPlayerBetsUseCaseResponse GetVictoriousPlayerBetsUseCase::execute(const std::vector<Bet>& openBets, const Card::Suit& victoriousSuit)
{
    std::vector<Bet> victoriousBets;

    for (Bet openBet : openBets)
    {
        if (openBet.getSuit() == victoriousSuit)
        {
            victoriousBets.push_back(openBet);
        }
    }

    return GetVictoriousPlayerBetsUseCaseResponse(victoriousBets);
}
