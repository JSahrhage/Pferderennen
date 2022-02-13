// C++ Library Includes
#include <iostream>

// Project Includes
#include "QView.h"

QView::QView(std::shared_ptr<Model> model) : m_model(model)
{
    if (model == nullptr)
    {
        throw std::invalid_argument("model must not be null");
    }

    this->m_mainWindow->setStyleSheet("background-color: #2D2D30");
    this->m_mainWindow->setWindowTitle("Pferderennen");
    this->m_mainWindow->showMaximized();
}

void QView::setModel(std::shared_ptr<Model> model)
{
    if (model == nullptr)
    {
        throw std::invalid_argument("model must not be null");
    }

    this->m_model = model;
}

void QView::setController(std::shared_ptr<IController> controller)
{
    if (controller == nullptr)
    {
        throw std::invalid_argument("controller must not be null");
    }

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
