// Project Includes
#include "QPlaceBetsWidget.h"
#include "AssetConfig.h"

QPlaceBetsWidget::QPlaceBetsWidget(std::shared_ptr<Model> model, std::shared_ptr<IConfig> assetConfig, QWidget* parent) : m_model(model), m_assetConfig(assetConfig)
{
    generateGeneralLayout();
    connects();
}

QPlaceBetsWidget::~QPlaceBetsWidget()
{

}

void QPlaceBetsWidget::connects()
{
#pragma warning(disable:26444)

}

void QPlaceBetsWidget::setController(std::shared_ptr<IController> controller)
{
    this->m_controller = controller;
}

void QPlaceBetsWidget::generateGeneralLayout()
{
    std::string pathToAssets = std::dynamic_pointer_cast<AssetConfig>(this->m_assetConfig)->getPathToAssets();

    QPixmap logoLabelPixmap(QString::fromStdString(pathToAssets + "/placeBetsAssets/Logo.png"));
    logoLabelPixmap = logoLabelPixmap.scaled(m_logoLabel->size() / 2);
    m_logoLabel->setPixmap(logoLabelPixmap);

    QPixmap chooseGameModePushButtonPixmap(QString::fromStdString(pathToAssets + "/placeBetsAssets/ChooseGameModeButtonIcon.png"));
    QIcon chooseGameModePushButtonIcon(chooseGameModePushButtonPixmap);
    m_chooseGameModePushButton->setIcon(chooseGameModePushButtonIcon);
    m_chooseGameModePushButton->setIconSize(QSize(256, 48));

    QPixmap enterPlayerPushButtonPixmap(QString::fromStdString(pathToAssets + "/placeBetsAssets/EnterPlayerButtonIcon.png"));
    QIcon enterPlayerPushButtonIcon(enterPlayerPushButtonPixmap);
    m_enterPlayerPushButton->setIcon(enterPlayerPushButtonIcon);
    m_enterPlayerPushButton->setIconSize(QSize(256, 48));

    QPixmap proceedPushButtonPixmap(QString::fromStdString(pathToAssets + "/placeBetsAssets/ProceedButtonIcon.png"));
    QIcon proceedPushButtonIcon(proceedPushButtonPixmap);
    m_proceedPushButton->setIcon(proceedPushButtonIcon);
    m_proceedPushButton->setIconSize(QSize(256, 48));

    m_playersWidgetTopWidget->setLayout(m_playersWidgetTopWidgetLayout);

    m_pushButtonsWidgetLayout->addWidget(m_chooseGameModePushButton, Qt::AlignCenter);
    m_pushButtonsWidgetLayout->addWidget(m_enterPlayerPushButton, Qt::AlignCenter);
    m_pushButtonsWidgetLayout->addWidget(m_proceedPushButton, Qt::AlignCenter);

    m_pushButtonsWidget->setLayout(m_pushButtonsWidgetLayout);

    m_playersWidgetMainLayout->addWidget(m_playersWidgetTopWidget, Qt::AlignCenter);
    m_playersWidgetMainLayout->addWidget(m_pushButtonsWidget, Qt::AlignCenter);

    m_playersWidget->setFixedSize(QSize(1024, 640));
    m_playersWidget->setLayout(m_playersWidgetMainLayout);

    m_mainLayout->addWidget(m_logoLabel, 12, Qt::AlignCenter);
    m_mainLayout->addWidget(m_playersWidget, 14, Qt::AlignCenter);

    this->setLayout(m_mainLayout);
}

void QPlaceBetsWidget::updateUI()
{

}
