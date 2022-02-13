// C++ Library Includes
#include <iostream>

// Project Includes
#include "QSelectGameModeWidget.h"

QSelectGameModeWidget::QSelectGameModeWidget(QWidget* parent) : QWidget(parent)
{
    GenerateGeneralLayout();
    Connects();
}

QSelectGameModeWidget::~QSelectGameModeWidget()
{

}

void QSelectGameModeWidget::Connects()
{
#pragma warning(disable:26444)

}

void QSelectGameModeWidget::setController(std::shared_ptr<IController> controller)
{
    if (controller == nullptr)
    {
        throw std::invalid_argument("controller must not be null");
    }

    this->m_controller = controller;
}

void QSelectGameModeWidget::GenerateGeneralLayout()
{
    QHBoxLayout* layout = new QHBoxLayout();
    QPushButton* button = new QPushButton();
    button->setText("Test");
    button->setStyleSheet("color: red");
    layout->addWidget(button);

    connect(button, &QPushButton::clicked, this, &QSelectGameModeWidget::printStuff);

    this->setLayout(layout);
}

void QSelectGameModeWidget::printStuff()
{
    m_controller->printStuff();
}
