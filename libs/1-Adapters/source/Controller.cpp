// Project Includes
#include <iostream>
#include "MagicEnum.h"
#include "Controller.h"
#include "Player.h"
#include "Bet.h"

// UseCases
#include "InitializeGameUseCase.h"
#include "DrawCardUseCase.h"

Controller::Controller(std::shared_ptr<Model> model, std::shared_ptr<IView> view) : m_model(model), m_view(view)
{

}

void Controller::onLoad()
{
    this->m_model->notify();
}

void Controller::classicModePushButtonClicked()
{
    this->m_model->setGameMode(Game::Mode::Classic);
    this->m_model->setGameView(Game::View::EnterPlayer);
}

void Controller::advancedModePushButtonClicked()
{
    this->m_model->setGameMode(Game::Mode::Advanced);
    this->m_model->setGameView(Game::View::EnterPlayer);
}

void Controller::enterPlayerProceedButtonClicked(const std::vector<std::string>& players)
{
    std::vector<Player> castedPlayer;
    for (const auto& player : players)
    {
        if (player.empty())
        {
            continue;
        }

        castedPlayer.push_back(Player(player));
    }

    if (castedPlayer.size() < 2)
    {
        return;
    }

    this->m_model->setPlayer(castedPlayer);
    this->m_model->setGameView(Game::View::PlaceBets);
}

void Controller::placeBetsChooseGameModeButtonClicked()
{
    this->m_model->setGameView(Game::View::ChooseGameMode);
}

void Controller::placeBetsEnterPlayerButtonClicked()
{
    this->m_model->setGameView(Game::View::EnterPlayer);
}

void Controller::placeBetsProceedButtonClicked(const std::vector<std::tuple<std::string, std::string, int>>& bets)
{
    std::vector<Bet> castedBets;
    for (const auto& bet : bets)
    {
        Player player = Player(std::get<0>(bet));
        auto suit = magic_enum::enum_cast<Card::Suit>(std::get<1>(bet)).value();
        int sips = std::get<2>(bet);
        castedBets.push_back(Bet(player, suit, sips));
    }

    this->m_model->setOpenBets(castedBets);

    InitializeGameUseCaseResponse initializeGameUseCaseResponse = InitializeGameUseCase::execute();

    this->m_model->setDiamondPosition(0);
    this->m_model->setHeartPosition(0);
    this->m_model->setSpadePosition(0);
    this->m_model->setClubPosition(0);
    this->m_model->setDeck(initializeGameUseCaseResponse.getDeck());
    this->m_model->setHurdles(initializeGameUseCaseResponse.getHurdles());

    this->m_model->setGameView(Game::View::Game);
}

void Controller::gameDrawButtonClicked()
{
    short diamondPosition = this->m_model->getDiamondPosition();
    short heartPosition = this->m_model->getHeartPosition();
    short spadePosition = this->m_model->getSpadePosition();
    short clubPosition = this->m_model->getClubPosition();
    Card::Deck deck = this->m_model->getDeck();
    std::vector<std::pair<Card::Card, bool>> hurdles = this->m_model->getHurdles();

    DrawCardUseCaseResponse drawCardUseCaseResponse = DrawCardUseCase::execute(diamondPosition,
                                                                               heartPosition,
                                                                               spadePosition,
                                                                               clubPosition,
                                                                               deck,
                                                                               hurdles);

    this->m_model->setFirstCardDrawn(true);

    this->m_model->setDiamondPosition(drawCardUseCaseResponse.getDiamondPosition());
    this->m_model->setHeartPosition(drawCardUseCaseResponse.getHeartPosition());
    this->m_model->setSpadePosition(drawCardUseCaseResponse.getSpadePosition());
    this->m_model->setClubPosition(drawCardUseCaseResponse.getClubPosition());
    this->m_model->setDeck(drawCardUseCaseResponse.getDeck());
    this->m_model->setLastDrawnCard(drawCardUseCaseResponse.getDrawnCard());
    this->m_model->setHurdles(drawCardUseCaseResponse.getHurdles());
    this->m_model->setGameDrawButtonActive(drawCardUseCaseResponse.getGameDrawButtonActive());
    this->m_model->setGameProceedButtonActive(drawCardUseCaseResponse.getGameProceedButtonActive());

    this->m_model->notify();
}

void Controller::gameProceedButtonClicked()
{
    this->m_model->setGameView(Game::View::DistributeSips);
}
