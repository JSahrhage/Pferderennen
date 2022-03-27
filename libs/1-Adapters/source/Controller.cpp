// Project Includes
#include "MagicEnum.h"
#include "Controller.h"
#include "Player.h"
#include "Bet.h"

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
    this->m_model->setGameView(Game::View::Game);
}

void Controller::gameDrawButtonClicked()
{

}

void Controller::gameProceedButtonClicked()
{

}
