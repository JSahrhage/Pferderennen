#ifndef Q_SELECT_GAME_MODE_WIDGET_H
#define Q_SELECT_GAME_MODE_WIDGET_H

// C++ Library Includes
#include <memory>

// Qt Includes
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

// Project Includes
#include "IConfig.h"
#include "IController.h"

class QSelectGameModeWidget : public QWidget
{
	Q_OBJECT

Q_SIGNALS:

public:
// Public Functions
	explicit QSelectGameModeWidget(std::shared_ptr<IConfig> assetConfig, QWidget* parent = nullptr);
	~QSelectGameModeWidget();

	void setController(std::shared_ptr<IController> controller);

private:
// Private Functions
	void Connects();

	void GenerateGeneralLayout();

	void printStuff();

// Variables
	std::shared_ptr<IConfig> m_assetConfig = nullptr;
	std::shared_ptr<IController> m_controller = nullptr;

// Widgets
	QVBoxLayout* mainLayout = new QVBoxLayout;

	QPushButton* loadSavedGamePushButton = new QPushButton;
	QLabel* logoLabel = new QLabel;
	QPushButton* classicModePushButton = new QPushButton;
	QPushButton* advancedModePushButton = new QPushButton;
};

#endif // Q_SELECT_GAME_MODE_WIDGET_H
