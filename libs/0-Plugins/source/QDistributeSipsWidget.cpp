// Project Includes
#include "QDistributeSipsWidget.h"
#include "AssetConfig.h"

QDistributeSipsWidget::QDistributeSipsWidget(std::shared_ptr<Model> model, std::shared_ptr<IConfig> assetConfig, QWidget* parent) : m_model(model), m_assetConfig(assetConfig)
{
    generateGeneralLayout();
    connects();
}

QDistributeSipsWidget::~QDistributeSipsWidget()
{

}

void QDistributeSipsWidget::connects()
{
#pragma warning(disable:26444)

}

void QDistributeSipsWidget::setController(std::shared_ptr<IController> controller)
{
    this->m_controller = controller;
}

void QDistributeSipsWidget::generateGeneralLayout()
{
    std::string pathToAssets = std::dynamic_pointer_cast<AssetConfig>(this->m_assetConfig)->getPathToAssets();

    QPixmap logoLabelPixmap(QString::fromStdString(pathToAssets + "/distributeSipsAssets/Logo.png"));
    logoLabelPixmap = logoLabelPixmap.scaled(m_logoLabel->size());
    m_logoLabel->setPixmap(logoLabelPixmap);

    QPixmap addNewPlayerRowPushButtonPixmap(QString::fromStdString(pathToAssets + "/distributeSipsAssets/ProceedButtonIcon.png"));
    QIcon addNewPlayerRowPushButtonIcon(addNewPlayerRowPushButtonPixmap);
    m_proceedPushButton->setIcon(addNewPlayerRowPushButtonIcon);
    m_proceedPushButton->setIconSize(QSize(256, 48));

    m_playersWidgetTopWidget->setLayout(m_playersWidgetTopWidgetLayout);

    m_playersWidgetMainLayout->addWidget(m_playersWidgetTopWidget, Qt::AlignCenter);
    m_playersWidgetMainLayout->addWidget(m_proceedPushButton, Qt::AlignCenter);

    m_playersWidget->setFixedSize(QSize(1024, 448));
    m_playersWidget->setLayout(m_playersWidgetMainLayout);

    m_mainLayout->addWidget(m_logoLabel, 12, Qt::AlignCenter);
    m_mainLayout->addWidget(m_playersWidget, 14, Qt::AlignCenter);

    this->setLayout(m_mainLayout);
}

void QDistributeSipsWidget::updateUI()
{

}
