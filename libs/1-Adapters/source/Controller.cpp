// Project Includes
#include "Controller.h"
#include "Player.h"

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

    this->m_model->setPlayer(castedPlayer);
    this->m_model->setGameView(Game::View::PlaceBets);
}
