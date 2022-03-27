#ifndef SIZE_CONFIG_H
#define SIZE_CONFIG_H

// Project Includes
#include "IConfig.h"

class SizeConfig : public IConfig
{
public:
    SizeConfig(int cardWidth, int cardHeight) : m_cardWidth(cardWidth), m_cardHeight(cardHeight) {}

    int getCardWidth() { return this->m_cardWidth; }
    int getCardHeight() { return this->m_cardHeight; }

private:
    int m_cardWidth;
    int m_cardHeight;
};

#endif // SIZE_CONFIG_H
