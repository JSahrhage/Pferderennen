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
	QPushButton* m_loadSavedGamePushButton = new QPushButton;
	QLabel* m_logoLabel = new QLabel;
	QPushButton* m_classicModePushButton = new QPushButton;
	QPushButton* m_advancedModePushButton = new QPushButton;
	QVBoxLayout* m_mainLayout = new QVBoxLayout;
};

#endif // Q_SELECT_GAME_MODE_WIDGET_H
