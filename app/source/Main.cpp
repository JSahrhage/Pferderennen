// C++ Library Includes
#include <iostream>
#include <string>
#include <memory>

// Qt Includes
#include <QApplication>

// Project Includes
#include "Main.h"
#include "AssetConfig.h"
#include "SizeConfig.h"
#include "QView.h"
#include "Controller.h"
#include "GameView.h"

int main(int argc, char *argv[])
{
    std::shared_ptr<AssetConfig> assetConfig = std::make_shared<AssetConfig>(AssetConfig("../../src/assets"));
    std::shared_ptr<SizeConfig> sizeConfig = std::make_shared<SizeConfig>(SizeConfig(192, 128));

    QApplication application = QApplication(argc, argv);
    std::shared_ptr<Model> model = std::make_shared<Model>(Model());
    std::shared_ptr<QView> view = std::make_shared<QView>(QView(model, assetConfig, sizeConfig));
    Controller controller = Controller(model);

    model->attach(view);
    view->setController(&controller);

    controller.onLoad();

    view->getMainWindow()->show();
    return application.exec();
}
