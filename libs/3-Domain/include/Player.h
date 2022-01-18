#ifndef PLAYER_H
#define PLAYER_H

// C++ Library Includes
#include <string>

class Player
{
public:
    Player(const std::string& name) : m_name(name) {}

    std::string getName() { return this->m_name; }

private:
    std::string m_name;
};

#endif PLAYER_H
