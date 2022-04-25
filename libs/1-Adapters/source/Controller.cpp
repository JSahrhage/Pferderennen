// C++ Library Includes
#include <iostream>

// Project Includes
#include "Controller.h"
#include "Player.h"
#include "Bet.h"

// UseCases
#include "DrawCardUseCase.h"
#include "EnterPlayerUseCase.h"
#include "GetVictoriousPlayerBetsUseCase.h"
#include "InitializeGameUseCase.h"
#include "ShuffleDeckUseCase.h"

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
    EnterPlayerUseCaseResponse enterPlayerUseCaseResponse = EnterPlayerUseCase::execute(players);

    this->m_model->setPlayer(enterPlayerUseCaseResponse.getPlayer());

    if (enterPlayerUseCaseResponse.getEnoughPlayer())
    {
        this->m_model->setGameView(Game::View::PlaceBets);
    }
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
    InitializeGameUseCaseResponse initializeGameUseCaseResponse = InitializeGameUseCase::execute(bets);

    ShuffleDeckUseCaseResponse shuffleDeckUseCaseResponse = ShuffleDeckUseCase::execute(initializeGameUseCaseResponse.getDeck());

    this->m_model->setOpenBets(initializeGameUseCaseResponse.getBets());

    this->m_model->setFirstCardDrawn(false);

    this->m_model->setDiamondPosition(0);
    this->m_model->setHeartPosition(0);
    this->m_model->setSpadePosition(0);
    this->m_model->setClubPosition(0);
    this->m_model->setDeck(shuffleDeckUseCaseResponse.getDeck());
    this->m_model->setHurdles(initializeGameUseCaseResponse.getHurdles());
    this->m_model->setGameDrawButtonActive(true);
    this->m_model->setGameProceedButtonActive(false);

    this->m_model->setGameView(Game::View::Game);
}

void Controller::gameDrawButtonClicked()
{
    short diamondPosition = this->m_model->getDiamondPosition();
    short heartPosition = this->m_model->getHeartPosition();
    short spadePosition = this->m_model->getSpadePosition();
    short clubPosition = this->m_model->getClubPosition();
    Card::Deck deck = this->m_model->getDeck();
    Card::Card lastDrawnCard = this->m_model->getLastDrawnCard();
    std::vector<std::pair<Card::Card, bool>> hurdles = this->m_model->getHurdles();

    DrawCardUseCaseResponse drawCardUseCaseResponse = DrawCardUseCase::execute(diamondPosition,
                                                                               heartPosition,
                                                                               spadePosition,
                                                                               clubPosition,
                                                                               deck,
                                                                               lastDrawnCard,
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
    this->m_model->setVictoriousSuit(drawCardUseCaseResponse.getVictoriousSuit());

    this->m_model->notify();
}

void Controller::gameProceedButtonClicked()
{
    std::vector<Bet> openBets = this->m_model->getOpenBets();
    Card::Suit victoriousSuit = this->m_model->getVictoriousSuit();

    GetVictoriousPlayerBetsUseCaseResponse getVictoriousPlayerBetsUseCaseResponse = 
        GetVictoriousPlayerBetsUseCase::execute(openBets, victoriousSuit);

    this->m_model->setVictoriousBets(getVictoriousPlayerBetsUseCaseResponse.getVictoriousBets());

    this->m_model->setGameView(Game::View::DistributeSips);
}

void Controller::distributeSipsProceedButtonClicked()
{
    this->m_model->setGameView(Game::View::PlaceBets);
}
