#ifndef SIP_DISTRIBUTON_H
#define SIP_DISTRIBUTON_H

// Project Includes
#include "Player.h"

class SipDistribution
{
public:
    SipDistribution(const Player& player, const int& amount) : m_player(player), m_amount(amount) {}

private:
    Player m_player;
    int m_amount;
};

#endif // SIP_DISTRIBUTION_H
