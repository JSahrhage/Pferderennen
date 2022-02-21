#ifndef Q_SELECT_GAME_MODE_WIDGET_H
#define Q_SELECT_GAME_MODE_WIDGET_H

// Qt Includes
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

// Project Includes
#include "IQViewWidget.h"
#include "IConfig.h"

class QSelectGameModeWidget : public IQViewWidget
{
public:
// Public Functions
	explicit QSelectGameModeWidget(std::shared_ptr<IConfig> assetConfig, QWidget* parent = nullptr);
	~QSelectGameModeWidget();

	void setController(std::shared_ptr<IController> controller);

	void updateUI();

private:
// Private Functions
	void connects();

	void generateGeneralLayout();

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
