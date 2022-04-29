#ifndef CARD_CONVERTER_H
#define CARD_CONVERTER_H

// C++ Library Includes
#include <string>

// Project Includes
#include "Card.h"

namespace Card
{
    class Converter
    {
    public:
        static std::string convertToAcronym(Card& card);
    };
}

#endif // CARD_CONVERTER_H
