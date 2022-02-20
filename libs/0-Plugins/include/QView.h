#ifndef Q_VIEW_H
#define Q_VIEW_H

// C++ Library Includes
#include <memory>

// Qt Includes
#include <QMainWindow>

// Project Includes
#include "IView.h"
#include "IController.h"
#include "Model.h"
#include "IConfig.h"
#include "QSelectGameModeWidget.h"

class QView : public IView
{
public:
    QView(std::shared_ptr<Model> model, std::shared_ptr<IConfig> assetConfig);

    void setController(std::shared_ptr<IController> controller);

    void render();

    QMainWindow* getMainWindow() { return this->m_mainWindow; }

private:
    std::shared_ptr<Model> m_model = nullptr;
    std::shared_ptr<IController> m_controller = nullptr;
    std::shared_ptr<IConfig> m_assetConfig = nullptr;
    QMainWindow* m_mainWindow = new QMainWindow();
    QSelectGameModeWidget* m_selectGameModeWidget = nullptr;
};

#endif // Q_VIEW_H
