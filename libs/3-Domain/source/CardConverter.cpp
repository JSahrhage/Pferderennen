// Project Includes
#include "CardConverter.h"

namespace Card
{
    std::string Converter::convertToAcronym(Card& card)
    {
        std::string acronym;

        Pip cardPip = card.getPip();
        Suit cardSuit = card.getSuit();

        if (cardPip == Pip::Ace)
        {
            acronym.append("A");
        }
        else if (cardPip == Pip::Two)
        {
            acronym.append("2");
        }
        else if (cardPip == Pip::Three)
        {
            acronym.append("3");
        }
        else if (cardPip == Pip::Four)
        {
            acronym.append("4");
        }
        else if (cardPip == Pip::Five)
        {
            acronym.append("5");
        }
        else if (cardPip == Pip::Six)
        {
            acronym.append("6");
        }
        else if (cardPip == Pip::Seven)
        {
            acronym.append("7");
        }
        else if (cardPip == Pip::Eight)
        {
            acronym.append("8");
        }
        else if (cardPip == Pip::Nine)
        {
            acronym.append("9");
        }
        else if (cardPip == Pip::Ten)
        {
            acronym.append("10");
        }
        else if (cardPip == Pip::Jack)
        {
            acronym.append("J");
        }
        else if (cardPip == Pip::Queen)
        {
            acronym.append("Q");
        }
        else if (cardPip == Pip::King)
        {
            acronym.append("K");
        }

        if (cardSuit == Suit::Diamond)
        {
            acronym.append("D");
        }
        else if (cardSuit == Suit::Heart)
        {
            acronym.append("H");
        }
        else if (cardSuit == Suit::Spade)
        {
            acronym.append("S");
        }
        else if (cardSuit == Suit::Club)
        {
            acronym.append("C");
        }

        return acronym;
    }
}
