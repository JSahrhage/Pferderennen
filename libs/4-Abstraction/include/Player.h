#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
public:
    Player(const std::string& name) : m_name(name) {}

private:
    const std::string m_name;
};

#endif // PLAYER_H
