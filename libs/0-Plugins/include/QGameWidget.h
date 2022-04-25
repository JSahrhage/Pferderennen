#ifndef Q_GAME_WIDGET_H
#define Q_GAME_WIDGET_H

// Qt Includes
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

// Project Includes
#include "IQViewWidget.h"
#include "Model.h"
#include "IConfig.h"

class QGameWidget : public IQViewWidget
{
public:
	// Public Functions
	explicit QGameWidget(std::shared_ptr<Model> model, std::shared_ptr<IConfig> assetConfig, std::shared_ptr<IConfig> sizeConfig, QWidget* parent = nullptr);
	~QGameWidget();

	void setController(IController* controller);

	void updateUI();

	void drawButtonClicked();

private:
	// Private Functions
	void connects();

	void generateGeneralLayout();

	void proceedButtonClicked();

	void setUpPlayground();

	void setUpDeck();

	void setUpHurdles();

	void setUpProceedButton();

	void updatePlayground();

	void updateDeck();

	void updateHurdles();

	void updateProceedButton();

	// Variables
	std::shared_ptr<Model> m_model = nullptr;
	IController* m_controller = nullptr;
	std::shared_ptr<IConfig> m_assetConfig = nullptr;
	std::shared_ptr<IConfig> m_sizeConfig = nullptr;
	// Playground
	std::vector<QLabel*> m_diamondLabels;
	std::vector<QLabel*> m_heartLabels;
	std::vector<QLabel*> m_spadeLabels;
	std::vector<QLabel*> m_clubLabels;
	// Hurdles
	std::vector<QLabel*> m_hurdleLabels;

	// Widgets
	// Playground
	QWidget* m_playground = new QWidget;
	QHBoxLayout* m_diamondLayout = new QHBoxLayout;
	QHBoxLayout* m_heartLayout = new QHBoxLayout;
	QHBoxLayout* m_spadeLayout = new QHBoxLayout;
	QHBoxLayout* m_clubLayout = new QHBoxLayout;
	// Deck
	QWidget* m_deck = new QWidget;
	QVBoxLayout* m_deckLayout = new QVBoxLayout;
	QLabel* m_closedCardLabel = new QLabel;
	QLabel* m_openedCardLabel = new QLabel;
	QPushButton* m_drawPushButton = new QPushButton;
	// Hurdles
	QWidget* m_hurdles = new QWidget;
	QHBoxLayout* m_hurdlesLayout = new QHBoxLayout;
	// Buttons
	QWidget* m_proceedButtonWidget = new QWidget;
	QPushButton* m_proceedPushButton = new QPushButton;
};

#endif // Q_GAME_WIDGET_H
