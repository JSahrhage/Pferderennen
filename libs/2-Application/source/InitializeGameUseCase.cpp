// Project Includes
#include "InitializeGameUseCase.h"
#include "MagicEnum.h"

InitializeGameUseCaseResponse InitializeGameUseCase::execute(const std::vector<std::tuple<std::string, std::string, int>>& bets)
{
    std::vector<Bet> castedBets;
    for (const auto& bet : bets)
    {
        Player player = Player(std::get<0>(bet));
        auto suit = magic_enum::enum_cast<Card::Suit>(std::get<1>(bet)).value();
        int sips = std::get<2>(bet);
        castedBets.push_back(Bet(player, suit, sips));
    }

    Card::Deck deck = Card::Deck(Card::DeckType(Card::SuitConstants::AllSuits, Card::PipConstants::PiquetPipsWithoutAces));
    std::vector<std::pair<Card::Card, bool>> hurdles;
    for (int i = 0; i < 5; i++)
    {
        hurdles.insert(hurdles.begin(), std::make_pair(deck.draw(), false));
    }

    return InitializeGameUseCaseResponse(castedBets, deck, hurdles);
}
