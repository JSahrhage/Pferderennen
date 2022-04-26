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
    ASSERT_EQ(drawCardUseCaseRespones.getHeartPosition(), 0);
    ASSERT_EQ(drawCardUseCaseRespones.getSpadePosition(), 0);
    ASSERT_EQ(drawCardUseCaseRespones.getClubPosition(), 0);
}

TEST(DrawDiamondCardWithPositiveHurdle, DrawCardTest)
{
    short diamondPosition = 0;
    short heartPosition = 1;
    short spadePosition = 1;
    short clubPosition = 1;

    std::vector<Card::Card> cards{ Card::Card(Card::Identifier(Card::Suit::Diamond, Card::Pip::Seven)) };
    Card::Deck deck = Card::Deck(cards);

    Card::Card lastDrawnCard = Card::Card(Card::Identifier(Card::Suit::Club, Card::Pip::Seven));

    std::vector<std::pair<Card::Card, bool>> hurdles{ std::make_pair(Card::Card(Card::Identifier(Card::Suit::Heart, Card::Pip::Ten)), false) };

    DrawCardUseCaseResponse drawCardUseCaseRespones = DrawCardUseCase::execute(diamondPosition,
                                                                               heartPosition,
                                                                               spadePosition,
                                                                               clubPosition,
                                                                               deck,
                                                                               lastDrawnCard,
                                                                               hurdles);

    ASSERT_EQ(drawCardUseCaseRespones.getDiamondPosition(), 1);
    ASSERT_EQ(drawCardUseCaseRespones.getHeartPosition(), 2);
    ASSERT_EQ(drawCardUseCaseRespones.getSpadePosition(), 1);
    ASSERT_EQ(drawCardUseCaseRespones.getClubPosition(), 1);
}

TEST(DrawDiamondCardWithNegativeHurdle, DrawCardTest)
{
    short diamondPosition = 0;
    short heartPosition = 1;
    short spadePosition = 1;
    short clubPosition = 1;

    std::vector<Card::Card> cards{ Card::Card(Card::Identifier(Card::Suit::Diamond, Card::Pip::Seven)) };
    Card::Deck deck = Card::Deck(cards);

    Card::Card lastDrawnCard = Card::Card(Card::Identifier(Card::Suit::Club, Card::Pip::Seven));

    std::vector<std::pair<Card::Card, bool>> hurdles{ std::make_pair(Card::Card(Card::Identifier(Card::Suit::Heart, Card::Pip::Seven)), false) };

    DrawCardUseCaseResponse drawCardUseCaseRespones = DrawCardUseCase::execute(diamondPosition,
        heartPosition,
        spadePosition,
        clubPosition,
        deck,
        lastDrawnCard,
        hurdles);

    ASSERT_EQ(drawCardUseCaseRespones.getDiamondPosition(), 1);
    ASSERT_EQ(drawCardUseCaseRespones.getHeartPosition(), 0);
    ASSERT_EQ(drawCardUseCaseRespones.getSpadePosition(), 1);
    ASSERT_EQ(drawCardUseCaseRespones.getClubPosition(), 1);
}

TEST(CheckWin, DrawCardTest)
{
    short diamondPosition = 5;
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

    ASSERT_EQ(drawCardUseCaseRespones.getDiamondPosition(), 6);
    ASSERT_EQ(drawCardUseCaseRespones.getHeartPosition(), 0);
    ASSERT_EQ(drawCardUseCaseRespones.getSpadePosition(), 0);
    ASSERT_EQ(drawCardUseCaseRespones.getClubPosition(), 0);
    ASSERT_EQ(drawCardUseCaseRespones.getVictoriousSuit(), Card::Suit::Diamond);
    ASSERT_EQ(drawCardUseCaseRespones.getGameDrawButtonActive(), false);
}

TEST(CheckWinAfterHurdle, DrawCardTest)
{
    short diamondPosition = 5;
    short heartPosition = 0;
    short spadePosition = 1;
    short clubPosition = 1;

    std::vector<Card::Card> cards{ Card::Card(Card::Identifier(Card::Suit::Heart, Card::Pip::Seven)) };
    Card::Deck deck = Card::Deck(cards);

    Card::Card lastDrawnCard = Card::Card(Card::Identifier(Card::Suit::Club, Card::Pip::Seven));

    std::vector<std::pair<Card::Card, bool>> hurdles{ std::make_pair(Card::Card(Card::Identifier(Card::Suit::Diamond, Card::Pip::Ten)), false) };

    DrawCardUseCaseResponse drawCardUseCaseRespones = DrawCardUseCase::execute(diamondPosition,
                                                                               heartPosition,
                                                                               spadePosition,
                                                                               clubPosition,
                                                                               deck,
                                                                               lastDrawnCard,
                                                                               hurdles);

    ASSERT_EQ(drawCardUseCaseRespones.getDiamondPosition(), 6);
    ASSERT_EQ(drawCardUseCaseRespones.getHeartPosition(), 1);
    ASSERT_EQ(drawCardUseCaseRespones.getSpadePosition(), 1);
    ASSERT_EQ(drawCardUseCaseRespones.getClubPosition(), 1);
    ASSERT_EQ(drawCardUseCaseRespones.getVictoriousSuit(), Card::Suit::Diamond);
    ASSERT_EQ(drawCardUseCaseRespones.getGameDrawButtonActive(), false);
}

TEST(CheckWinAfterHurdleWithOverPosition, DrawCardTest)
{
    short diamondPosition = 5;
    short heartPosition = 0;
    short spadePosition = 1;
    short clubPosition = 1;

    std::vector<Card::Card> cards{ Card::Card(Card::Identifier(Card::Suit::Heart, Card::Pip::Seven)) };
    Card::Deck deck = Card::Deck(cards);

    Card::Card lastDrawnCard = Card::Card(Card::Identifier(Card::Suit::Club, Card::Pip::Seven));

    std::vector<std::pair<Card::Card, bool>> hurdles{ std::make_pair(Card::Card(Card::Identifier(Card::Suit::Diamond, Card::Pip::King)), false) };

    DrawCardUseCaseResponse drawCardUseCaseRespones = DrawCardUseCase::execute(diamondPosition,
        heartPosition,
        spadePosition,
        clubPosition,
        deck,
        lastDrawnCard,
        hurdles);

    ASSERT_EQ(drawCardUseCaseRespones.getDiamondPosition(), 6);
    ASSERT_EQ(drawCardUseCaseRespones.getHeartPosition(), 1);
    ASSERT_EQ(drawCardUseCaseRespones.getSpadePosition(), 1);
    ASSERT_EQ(drawCardUseCaseRespones.getClubPosition(), 1);
    ASSERT_EQ(drawCardUseCaseRespones.getVictoriousSuit(), Card::Suit::Diamond);
    ASSERT_EQ(drawCardUseCaseRespones.getGameDrawButtonActive(), false);
}
