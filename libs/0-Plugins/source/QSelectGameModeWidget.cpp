// C++ Library Includes
#include <iostream>

// Project Includes
#include "QSelectGameModeWidget.h"
#include "AssetConfig.h"

QSelectGameModeWidget::QSelectGameModeWidget(std::shared_ptr<IConfig> assetConfig, QWidget* parent) : m_assetConfig(assetConfig)
{
    generateGeneralLayout();
    connects();
}

QSelectGameModeWidget::~QSelectGameModeWidget()
{

}

void QSelectGameModeWidget::connects()
{
    connect(this->m_classicModePushButton, &QPushButton::clicked, this, &QSelectGameModeWidget::classicModePushButtonClicked);
    connect(this->m_advancedModePushButton, &QPushButton::clicked, this, &QSelectGameModeWidget::advancedModePushButtonClicked);
}

void QSelectGameModeWidget::setController(IController* controller)
{
    this->m_controller = controller;
}

void QSelectGameModeWidget::generateGeneralLayout()
{
    std::string pathToAssets = std::dynamic_pointer_cast<AssetConfig>(this->m_assetConfig)->getPathToAssets();

    QPixmap logoLabelPixmap(QString::fromStdString(pathToAssets + "/chooseGameModeAssets/Logo.png"));
    logoLabelPixmap = logoLabelPixmap.scaled(m_logoLabel->size());
    m_logoLabel->setPixmap(logoLabelPixmap);

    QPixmap classicModePushButtonPixmap(QString::fromStdString(pathToAssets + "/chooseGameModeAssets/ClassicModeButtonIcon.png"));
    QIcon classicModePushButtonIcon(classicModePushButtonPixmap);
    m_classicModePushButton->setIcon(classicModePushButtonIcon);
    m_classicModePushButton->setIconSize(QSize(320, 160));

    QPixmap advancedModePushButtonPixmap(QString::fromStdString(pathToAssets + "/chooseGameModeAssets/AdvancedModeButtonIcon.png"));
    QIcon advancedModePushButtonIcon(advancedModePushButtonPixmap);
    m_advancedModePushButton->setIcon(advancedModePushButtonIcon);
    m_advancedModePushButton->setIconSize(QSize(320, 160));

    m_mainLayout->addWidget(m_logoLabel, 12, Qt::AlignCenter);
    m_mainLayout->addWidget(m_classicModePushButton, 8, Qt::AlignCenter);
    m_mainLayout->addWidget(m_advancedModePushButton, 8, Qt::AlignCenter);

    this->setLayout(m_mainLayout);
}

void QSelectGameModeWidget::updateUI()
{

}

void QSelectGameModeWidget::classicModePushButtonClicked()
{
    m_controller->classicModePushButtonClicked();
}

void QSelectGameModeWidget::advancedModePushButtonClicked()
{
    m_controller->advancedModePushButtonClicked();
}
