#ifndef Q_DISTRIBUTE_SIPS_WIDGET_H
#define Q_DISTRIBUTE_SIPS_WIDGET_H

// Qt Includes
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QIcon>
#include <QSize>
#include <QTextEdit>
#include <QColor>
#include <QGridLayout>
#include <QSpinBox>

// Project Includes
#include "IQViewWidget.h"
#include "Model.h"
#include "IConfig.h"

class QDistributeSipsWidget : public IQViewWidget
{
public:
	// Public Functions
	explicit QDistributeSipsWidget(std::shared_ptr<Model> model, std::shared_ptr<IConfig> assetConfig, QWidget* parent = nullptr);
	~QDistributeSipsWidget();

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
	QLabel* m_logoLabel = new QLabel;
	QPushButton* m_proceedPushButton = new QPushButton;
	QWidget* m_playersWidget = new QWidget;
	QVBoxLayout* m_playersWidgetMainLayout = new QVBoxLayout;
	QWidget* m_playersWidgetTopWidget = new QWidget;
	QGridLayout* m_playersWidgetTopWidgetLayout = new QGridLayout;
	QVBoxLayout* m_mainLayout = new QVBoxLayout;
};

#endif // Q_DISTRIBUTE_SIPS_WIDGET_H
