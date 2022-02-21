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
}

void QEnterPlayerWidget::updateUI()
{

}
