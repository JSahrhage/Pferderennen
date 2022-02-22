// Project Includes
#include "QGameWidget.h"
#include "AssetConfig.h"

QGameWidget::QGameWidget(std::shared_ptr<Model> model, std::shared_ptr<IConfig> assetConfig, QWidget* parent) : m_model(model), m_assetConfig(assetConfig)
{
    generateGeneralLayout();
    connects();
}

QGameWidget::~QGameWidget()
{

}

void QGameWidget::connects()
{
#pragma warning(disable:26444)

}

void QGameWidget::setController(std::shared_ptr<IController> controller)
{
    this->m_controller = controller;
}

void QGameWidget::generateGeneralLayout()
{
    std::string pathToAssets = std::dynamic_pointer_cast<AssetConfig>(this->m_assetConfig)->getPathToAssets();

}

void QGameWidget::updateUI()
{
    updatePlayground();
    updateDeck();
    updateHurdles();
    updateDrawButton();
}

void QGameWidget::updatePlayground()
{

}

void QGameWidget::updateDeck()
{

}

void QGameWidget::updateHurdles()
{

}

void QGameWidget::updateDrawButton()
{

}
