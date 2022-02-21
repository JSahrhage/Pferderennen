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
}

void QDistributeSipsWidget::updateUI()
{

}
