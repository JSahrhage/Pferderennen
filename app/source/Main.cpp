// C++ Library Includes
#include <iostream>
#include <string>
#include <memory>

// Qt Includes
#include <QApplication>

// Project Includes
#include "Main.h"
#include "AssetConfig.h"
#include "QView.h"
#include "Controller.h"
#include "GameView.h"

int main(int argc, char *argv[])
{
    std::shared_ptr<AssetConfig> assetConfig = std::make_shared<AssetConfig>(AssetConfig("../../src/dependencies"));

    QApplication application = QApplication(argc, argv);
    std::shared_ptr<Model> model = std::make_shared<Model>(Model());
    std::shared_ptr<QView> view = std::make_shared<QView>(QView(model, assetConfig));
    std::shared_ptr<Controller> controller = std::make_shared<Controller>(Controller(model, view));

    view->setController(controller);

    model->setGameView(Game::View::GameModeSelection);
    controller->onLoad();

    view->getMainWindow()->show();
    return application.exec();
}
