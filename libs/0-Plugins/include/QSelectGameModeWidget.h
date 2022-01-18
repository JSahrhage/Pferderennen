#ifndef Q_SELECT_GAME_MODE_WIDGET_H
#define Q_SELECT_GAME_MODE_WIDGET_H

// Qt Includes
#include <QMainWindow>
#include <QWidget>

// Project Includes
#include "GameModeSelector.h"

class QSelectGameModeWidget : public QWidget, public GameModeSelector
{
public:
    QSelectGameModeWidget(QMainWindow* mainWindow) : m_mainWindow(mainWindow) {}

    Game::Mode getGameModeSelection();

private:
    QMainWindow* m_mainWindow;
};

#endif // Q_SELECT_GAME_MODE_WIDGET_H
