// Project Includes
#include "Main.h"
#include "CardDeck.h"

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    Card::Deck cardDeck = Card::Deck(Card::DeckType(Card::allSuits, Card::piquetPips));
    return 0;
}
