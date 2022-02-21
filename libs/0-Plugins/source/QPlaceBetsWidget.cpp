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
}

void QPlaceBetsWidget::updateUI()
{

}
