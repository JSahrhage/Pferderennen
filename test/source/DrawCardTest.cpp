// Test Includes
#include "DrawCardTest.h"

// Project Includes
#include "DrawCardUseCase.h"

TEST(DrawEmptyDeck, DrawCardTest)
{
    short diamondPosition = 0;
    short heartPosition = 0;
    short spadePosition = 0;
    short clubPosition = 0;

    std::vector<Card::Card> cards;
    Card::Deck deck = Card::Deck(cards);

    Card::Card lastDrawnCard = Card::Card(Card::Identifier(Card::Suit::Diamond, Card::Pip::Seven));

    std::vector<std::pair<Card::Card, bool>> hurdles{};

    DrawCardUseCaseResponse drawCardUseCaseRespones = DrawCardUseCase::execute(diamondPosition,
                                                                               heartPosition,
                                                                               spadePosition,
                                                                               clubPosition,
                                                                               deck,
                                                                               lastDrawnCard,
                                                                               hurdles);

    bool lastDrawnCardEquality = drawCardUseCaseRespones.getDrawnCard() == lastDrawnCard;
    EXPECT_TRUE(lastDrawnCardEquality);
    ASSERT_EQ(drawCardUseCaseRespones.getDiamondPosition(), 0);
    ASSERT_EQ(drawCardUseCaseRespones.getHeartPosition(), 0);
    ASSERT_EQ(drawCardUseCaseRespones.getSpadePosition(), 0);
    ASSERT_EQ(drawCardUseCaseRespones.getClubPosition(), 0);
}

TEST(DrawDiamondCard, DrawCardTest)
{
    short diamondPosition = 0;
    short heartPosition = 0;
    short spadePosition = 0;
    short clubPosition = 0;

    std::vector<Card::Card> cards{ Card::Card(Card::Identifier(Card::Suit::Diamond, Card::Pip::Seven)) };
    Card::Deck deck = Card::Deck(cards);

    Card::Card lastDrawnCard = Card::Card(Card::Identifier(Card::Suit::Club, Card::Pip::Seven));

    std::vector<std::pair<Card::Card, bool>> hurdles{};

    DrawCardUseCaseResponse drawCardUseCaseRespones = DrawCardUseCase::execute(diamondPosition,
                                                                               heartPosition,
                                                                               spadePosition,
                                                                               clubPosition,
                                                                               deck,
                                                                               lastDrawnCard,
                                                                               hurdles);

    ASSERT_EQ(drawCardUseCaseRespones.getDiamondPosition(), 1);
}
