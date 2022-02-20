// C++ Library Includes
#include <iostream>

// Project Includes
#include "QView.h"

QView::QView(std::shared_ptr<Model> model, std::shared_ptr<IConfig> assetConfig) : m_model(model), m_assetConfig(assetConfig)
{
    this->m_selectGameModeWidget = new QSelectGameModeWidget(assetConfig);

    this->m_mainWindow->setStyleSheet("background-color: #2D2D30");
    this->m_mainWindow->setWindowTitle("Pferderennen");
    this->m_mainWindow->showMaximized();
}

void QView::setController(std::shared_ptr<IController> controller)
{
    this->m_controller = controller;
    this->m_selectGameModeWidget->setController(controller);
}

void QView::render()
{
    if (this->m_model->getGameView() == Game::View::GameModeSelection)
    {
        this->m_mainWindow->setCentralWidget(m_selectGameModeWidget);
    }
}
