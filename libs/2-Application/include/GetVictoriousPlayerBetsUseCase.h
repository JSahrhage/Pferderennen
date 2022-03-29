#ifndef GET_VICTORIOUS_PLAYER_BETS_USE_CASE_H
#define GET_VICTORIOUS_PLAYER_BETS_USE_CASE_H

// Project Includes
#include "Bet.h"

class GetVictoriousPlayerBetsUseCaseResponse
{
public:
    GetVictoriousPlayerBetsUseCaseResponse(std::vector<Bet> victoriousBets) : m_victoriousBets(victoriousBets) {}

    std::vector<Bet> getVictoriousBets() { return this->m_victoriousBets; }

private:
    std::vector<Bet> m_victoriousBets;
};

class GetVictoriousPlayerBetsUseCase
{
public:
    static GetVictoriousPlayerBetsUseCaseResponse execute(const std::vector<Bet>& openBets, const Card::Suit& victoriousSuit);

private:
    GetVictoriousPlayerBetsUseCase() {}
};

#endif // GET_VICTORIOUS_PLAYER_BETS_USE_CASE_H
