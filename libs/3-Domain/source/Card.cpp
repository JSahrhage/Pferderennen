// Project Includes
#include "Card.h"

namespace Card
{
    std::string Card::getAcronym()
    {
        std::string acronym;

        switch (this->m_identifier.getPip())
        {
            case Pip::Ace:
            {
                acronym.append("A");
                break;
            }
            case Pip::Two:
            {
                acronym.append("2");
                break;
            }
            case Pip::Three:
            {
                acronym.append("3");
                break;
            }
            case Pip::Four:
            {
                acronym.append("4");
                break;
            }
            case Pip::Five:
            {
                acronym.append("5");
                break;
            }
            case Pip::Six:
            {
                acronym.append("6");
                break;
            }
            case Pip::Seven:
            {
                acronym.append("7");
                break;
            }
            case Pip::Eight:
            {
                acronym.append("8");
                break;
            }
            case Pip::Nine:
            {
                acronym.append("9");
                break;
            }
            case Pip::Ten:
            {
                acronym.append("10");
                break;
            }
            case Pip::Jack:
            {
                acronym.append("J");
                break;
            }
            case Pip::Queen:
            {
                acronym.append("Q");
                break;
            }
            case Pip::King:
            {
                acronym.append("K");
                break;
            }
            default:
            {
                acronym.append("0");
            }
        }

        switch (this->m_identifier.getSuit())
        {
            case Suit::Diamond:
            {
                acronym.append("D");
                break;
            }
            case Suit::Heart:
            {
                acronym.append("H");
                break;
            }
            case Suit::Spade:
            {
                acronym.append("S");
                break;
            }
            case Suit::Club:
            {
                acronym.append("C");
                break;
            }
            default:
            {
                acronym.append("");
            }
        }

        return acronym;
    }
}
