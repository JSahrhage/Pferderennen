// Project Includes
#include "QEnterPlayerWidget.h"
#include "AssetConfig.h"

QEnterPlayerWidget::QEnterPlayerWidget(std::shared_ptr<Model> model, std::shared_ptr<IConfig> assetConfig, QWidget* parent) : m_model(model), m_assetConfig(assetConfig)
{
    generateGeneralLayout();
    connects();
}

QEnterPlayerWidget::~QEnterPlayerWidget()
{

}

void QEnterPlayerWidget::connects()
{
#pragma warning(disable:26444)

}

void QEnterPlayerWidget::setController(std::shared_ptr<IController> controller)
{
    this->m_controller = controller;
}

void QEnterPlayerWidget::generateGeneralLayout()
{
    std::string pathToAssets = std::dynamic_pointer_cast<AssetConfig>(this->m_assetConfig)->getPathToAssets();

    QPixmap logoLabelPixmap(QString::fromStdString(pathToDependencies + "/enterPlayerAssets/Logo.png"));
    logoLabelPixmap = logoLabelPixmap.scaled(m_logoLabel->size());
    m_logoLabel->setPixmap(logoLabelPixmap);

    QPixmap proceedPushButtonPixmap(QString::fromStdString(pathToDependencies + "/enterPlayerAssets/ProceedButtonIcon.png"));
    QIcon proceedPushButtonIcon(proceedPushButtonPixmap);
    m_proceedPushButton->setIcon(proceedPushButtonIcon);
    m_proceedPushButton->setIconSize(QSize(256, 48));

    m_playersWidgetTopWidget->setLayout(m_playersWidgetTopWidgetLayout);

    m_playersWidgetMainLayout->addWidget(m_playersWidgetTopWidget, Qt::AlignCenter);
    m_playersWidgetMainLayout->addWidget(m_proceedPushButton, Qt::AlignCenter);

    m_playersWidget->setFixedSize(QSize(1024, 448));
    m_playersWidget->setLayout(m_playersWidgetMainLayout);

    m_mainLayout->addWidget(m_statisticsPushButton, 1, Qt::AlignRight);
    m_mainLayout->addWidget(m_logoLabel, 12, Qt::AlignCenter);
    m_mainLayout->addWidget(m_playersWidget, 14, Qt::AlignCenter);

    this->setLayout(m_mainLayout);
}

void QEnterPlayerWidget::updateUI()
{

}
