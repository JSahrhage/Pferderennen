// C++ Library Includes
#include <iostream>

// Project Includes
#include "Card.h"
#include "MagicEnum.h"

namespace Card
{
    void Card::print() const
    {
        std::cout << magic_enum::enum_name(m_identifier.getSuit()) << " ";
        std::cout << magic_enum::enum_name(m_identifier.getPip()) << std::endl;
    }
}
