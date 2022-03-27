// C++ Library Includes
#include <iostream>

// Project Includes
#include "QView.h"

QView::QView(std::shared_ptr<Model> model, std::shared_ptr<IConfig> assetConfig, std::shared_ptr<IConfig> sizeConfig) : m_model(model)
{
    this->m_selectGameModeWidget = new QSelectGameModeWidget(assetConfig);
    this->m_enterPlayerWidget = new QEnterPlayerWidget(model, assetConfig);
    this->m_placeBetsWidget = new QPlaceBetsWidget(model, assetConfig);
    this->m_gameWidget = new QGameWidget(model, assetConfig, sizeConfig);
    this->m_distributeSipsWidget = new QDistributeSipsWidget(model, assetConfig);

    this->m_viewWidgets.insert_or_assign(Game::View::ChooseGameMode, this->m_selectGameModeWidget);
    this->m_viewWidgets.insert_or_assign(Game::View::EnterPlayer, this->m_enterPlayerWidget);
    this->m_viewWidgets.insert_or_assign(Game::View::PlaceBets, this->m_placeBetsWidget);
    this->m_viewWidgets.insert_or_assign(Game::View::Game, this->m_gameWidget);
    this->m_viewWidgets.insert_or_assign(Game::View::DistributeSips, this->m_distributeSipsWidget);
    
    for (const auto& [view, widget] : this->m_viewWidgets)
    {
        this->m_centralStackedWidget->addWidget(widget);
    }

    this->m_mainWindow->setCentralWidget(this->m_centralStackedWidget);
    this->m_mainWindow->setStyleSheet("background-color: #2D2D30");
    this->m_mainWindow->setWindowTitle("Pferderennen");
    this->m_mainWindow->setMinimumSize(1920, 1080);
}

void QView::setController(std::shared_ptr<IController> controller)
{
    for (auto const& [view, widget] : this->m_viewWidgets)
    {
        widget->setController(controller);
    }
}

void QView::update()
{
    for (const auto& [view, widget] : this->m_viewWidgets)
    {
        if (this->m_model->getGameView() == view)
        {
            widget->updateUI();
            this->m_centralStackedWidget->setCurrentWidget(widget);
            break;
        }
    }
}
