#ifndef Q_ENTER_PLAYER_WIDGET_H
#define Q_ENTER_PLAYER_WIDGET_H

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

	void setController(IController* controller);

	void updateUI();

private:
	// Private Functions
	void connects();

	void generateGeneralLayout();

	void addPlayerRows();

	void proceedButtonClicked();

	// Variables
	std::shared_ptr<Model> m_model = nullptr;
	std::shared_ptr<IConfig> m_assetConfig = nullptr;
	IController* m_controller = nullptr;
	std::vector<QTextEdit*> m_textEdits;

	// Widgets
	QLabel* m_logoLabel = new QLabel;
	QPushButton* m_proceedPushButton = new QPushButton;
	QWidget* m_playersWidget = new QWidget;
	QVBoxLayout* m_playersWidgetMainLayout = new QVBoxLayout;
	QWidget* m_playersWidgetTopWidget = new QWidget;
	QVBoxLayout* m_playersWidgetTopWidgetLayout = new QVBoxLayout;
	QVBoxLayout* m_mainLayout = new QVBoxLayout;
};

#endif // Q_ENTER_PLAYER_WIDGET_H
