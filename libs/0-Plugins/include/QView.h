#ifndef Q_VIEW_H
#define Q_VIEW_H

// C++ Library Includes
#include <map>

// Qt Includes
#include <QMainWindow>
#include <QStackedWidget>

// Project Includes
#include "IView.h"
#include "IController.h"
#include "Model.h"
#include "IConfig.h"
#include "GameView.h"
#include "QSelectGameModeWidget.h"
#include "QEnterPlayerWidget.h"
#include "QPlaceBetsWidget.h"
#include "QGameWidget.h"
#include "QDistributeSipsWidget.h"

class QView : public IView
{
public:
    QView(std::shared_ptr<Model> model, std::shared_ptr<IConfig> assetConfig, std::shared_ptr<IConfig> sizeConfig);

    void setController(IController* controller) override;

    void update() override;

    QMainWindow* getMainWindow() { return this->m_mainWindow; }

private:
    std::shared_ptr<Model> m_model = nullptr;
    QMainWindow* m_mainWindow = new QMainWindow();
    QStackedWidget* m_centralStackedWidget = new QStackedWidget();
    std::map<Game::View, IQViewWidget*> m_viewWidgets;
    QSelectGameModeWidget* m_selectGameModeWidget = nullptr;
    QEnterPlayerWidget* m_enterPlayerWidget = nullptr;
    QPlaceBetsWidget* m_placeBetsWidget = nullptr;
    QGameWidget* m_gameWidget = nullptr;
    QDistributeSipsWidget* m_distributeSipsWidget = nullptr;
};

#endif // Q_VIEW_H
