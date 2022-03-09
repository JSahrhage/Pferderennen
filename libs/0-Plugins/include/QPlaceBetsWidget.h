#ifndef Q_PLACE_BETS_WIDGET_H
#define Q_PLACE_BETS_WIDGET_H

// Qt Includes
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QIcon>
#include <QSize>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QColor>
#include <QComboBox>
#include <QLineEdit>
#include <QSpinBox>

// Project Includes
#include "IQViewWidget.h"
#include "Model.h"
#include "IConfig.h"

class QPlaceBetsWidget : public IQViewWidget
{
public:
	// Public Functions
	explicit QPlaceBetsWidget(std::shared_ptr<Model> model, std::shared_ptr<IConfig> assetConfig, QWidget* parent = nullptr);
	~QPlaceBetsWidget();

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
	QVBoxLayout* m_mainLayout = new QVBoxLayout;
	QWidget* m_playersWidget = new QWidget;
	QVBoxLayout* m_playersWidgetMainLayout = new QVBoxLayout;
	QWidget* m_playersWidgetTopWidget = new QWidget;
	QVBoxLayout* m_playersWidgetTopWidgetLayout = new QVBoxLayout;
	QWidget* m_pushButtonsWidget = new QWidget;
	QHBoxLayout* m_pushButtonsWidgetLayout = new QHBoxLayout;
	QLabel* m_logoLabel = new QLabel;
	QPushButton* m_chooseGameModePushButton = new QPushButton;
	QPushButton* m_enterPlayerPushButton = new QPushButton;
	QPushButton* m_proceedPushButton = new QPushButton;
};

#endif // Q_PLACE_BETS_WIDGET_H
