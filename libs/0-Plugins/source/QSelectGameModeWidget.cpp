// C++ Library Includes
#include <iostream>

// Project Includes
#include "QSelectGameModeWidget.h"
#include "AssetConfig.h"

QSelectGameModeWidget::QSelectGameModeWidget(std::shared_ptr<IConfig> assetConfig, QWidget* parent) : m_assetConfig(assetConfig), QWidget(parent)
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
    this->m_controller = controller;
}

void QSelectGameModeWidget::GenerateGeneralLayout()
{
    std::string pathToAssets = std::dynamic_pointer_cast<AssetConfig>(this->m_assetConfig)->getPathToAssets();

    QPixmap logoLabelPixmap(QString::fromStdString(pathToAssets + "/chooseGameModeAssets/Logo.png"));
    logoLabelPixmap = logoLabelPixmap.scaled(logoLabel->size());
    logoLabel->setPixmap(logoLabelPixmap);

    QPixmap classicModePushButtonPixmap(QString::fromStdString(pathToAssets + "/chooseGameModeAssets/ClassicModeButtonIcon.png"));
    QIcon classicModePushButtonIcon(classicModePushButtonPixmap);
    classicModePushButton->setIcon(classicModePushButtonIcon);
    classicModePushButton->setIconSize(QSize(320, 160));

    QPixmap advancedModePushButtonPixmap(QString::fromStdString(pathToAssets + "/chooseGameModeAssets/AdvancedModeButtonIcon.png"));
    QIcon advancedModePushButtonIcon(advancedModePushButtonPixmap);
    advancedModePushButton->setIcon(advancedModePushButtonIcon);
    advancedModePushButton->setIconSize(QSize(320, 160));

    mainLayout->addWidget(logoLabel, 12, Qt::AlignCenter);
    mainLayout->addWidget(classicModePushButton, 8, Qt::AlignCenter);
    mainLayout->addWidget(advancedModePushButton, 8, Qt::AlignCenter);

    this->setLayout(mainLayout);
}

void QSelectGameModeWidget::printStuff()
{
    m_controller->printStuff();
}
