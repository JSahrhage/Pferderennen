#ifndef Q_ENTER_PLAYER_WIDGET_H
#define Q_ENTER_PLAYER_WIDGET_H

// Qt Includes
#include <QWidget>

// Project Includes
#include "IQViewWidget.h"
#include "Model.h"
#include "IConfig.h"

class QEnterPlayerWidget : public IQViewWidget
{
public:
	// Public Functions
	explicit QEnterPlayerWidget(std::shared_ptr<Model> model, std::shared_ptr<IConfig> assetConfig, QWidget* parent = nullptr);
	~QEnterPlayerWidget();

	void setController(std::shared_ptr<IController> controller);

	void updateUI();

private:
	// Private Functions
	void connects();

	void generateGeneralLayout();

	// Variables
	std::shared_ptr<Model> m_model = nullptr;
	std::shared_ptr<IConfig> m_assetConfig = nullptr;
	std::shared_ptr<IController> m_controller = nullptr;

	// Widgets
};

#endif // Q_ENTER_PLAYER_WIDGET_H
