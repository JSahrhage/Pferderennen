// C++ Library Includes
#include <iostream>

// Project Includes
#include "QView.h"

QView::QView(std::shared_ptr<Model> model, std::shared_ptr<IConfig> assetConfig) : m_model(model)
{
    this->m_selectGameModeWidget = new QSelectGameModeWidget(assetConfig);
    this->m_enterPlayerWidget = new QEnterPlayerWidget(model, assetConfig);
    this->m_placeBetsWidget = new QPlaceBetsWidget(model, assetConfig);
    this->m_gameWidget = new QGameWidget(model, assetConfig);
    this->m_distributeSipsWidget = new QDistributeSipsWidget(model, assetConfig);

    this->m_viewWidgets.insert_or_assign(Game::View::SelectGameMode, this->m_selectGameModeWidget);
    this->m_viewWidgets.insert_or_assign(Game::View::EnterPlayer, this->m_enterPlayerWidget);
    this->m_viewWidgets.insert_or_assign(Game::View::PlaceBets, this->m_placeBetsWidget);
    this->m_viewWidgets.insert_or_assign(Game::View::Game, this->m_gameWidget);
    this->m_viewWidgets.insert_or_assign(Game::View::DistributeSips, this->m_distributeSipsWidget);

    this->m_mainWindow->setStyleSheet("background-color: #2D2D30");
    this->m_mainWindow->setWindowTitle("Pferderennen");
    this->m_mainWindow->showMaximized();
}

void QView::setWidgetController(std::shared_ptr<IController> controller)
{
    for (auto const& [view, widget] : this->m_viewWidgets)
    {
        widget->setController(controller);
    }
}

void QView::render()
{
    for (auto const& [view, widget] : this->m_viewWidgets)
    {
        if (this->m_model->getGameView() == view)
        {
            widget->updateUI();
            this->m_mainWindow->setCentralWidget(widget);
        }
    }
}
