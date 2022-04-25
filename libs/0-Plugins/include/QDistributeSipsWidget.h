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

class DistributionRow
{
public:
	DistributionRow(Player distributingPlayer, QLabel* sipsToDistributeLeftLabel, std::vector<std::pair<Player, QSpinBox*>> distributedSips) :
				    m_distributingPlayer(distributingPlayer),
					m_sipsToDistributeLeftLabel(sipsToDistributeLeftLabel),
					m_distributedSips(distributedSips) {}

	Player getDistributingPlayer() { return this->m_distributingPlayer; }
	QLabel* getSipsToDistributeLeftLabel() { return this->m_sipsToDistributeLeftLabel; }
	std::vector<std::pair<Player, QSpinBox*>> getDistributedSips() { return this->m_distributedSips; }
	
	void setAreSipsDistributed(const bool& areSipsDistributed) { this->m_areSipsDistributed = areSipsDistributed; }
	bool getAreSipsDistributed() { return this->m_areSipsDistributed; }

private:
	Player m_distributingPlayer;
	QLabel* m_sipsToDistributeLeftLabel;
	std::vector<std::pair<Player, QSpinBox*>> m_distributedSips;
	bool m_areSipsDistributed = false;
};

class QDistributeSipsWidget : public IQViewWidget
{
public:
	// Public Functions
	explicit QDistributeSipsWidget(std::shared_ptr<Model> model, std::shared_ptr<IConfig> assetConfig, QWidget* parent = nullptr);
	~QDistributeSipsWidget();

	void setController(IController* controller);

	void updateUI();

private:
	// Private Functions
	void connects();

	void generateGeneralLayout();

	void addDistributionRows();

	void updateSipsToDistributeLeftLabel();

	void checkAllSipsDistributed();

	void proceedButtonClicked();

	// Variables
	std::shared_ptr<Model> m_model = nullptr;
	std::shared_ptr<IConfig> m_assetConfig = nullptr;
	IController* m_controller = nullptr;

	std::vector<DistributionRow> m_distributionRows;

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
