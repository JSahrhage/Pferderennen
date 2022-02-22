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
	explicit QGameWidget(std::shared_ptr<Model> model, std::shared_ptr<IConfig> assetConfig, QWidget* parent = nullptr);
	~QGameWidget();

	void setController(std::shared_ptr<IController> controller);

	void updateUI();

private:
	// Private Functions
	void connects();

	void generateGeneralLayout();

	void updatePlayground();

	void updateDeck();

	void updateHurdles();

	void updateDrawButton();

	// Variables
	std::shared_ptr<Model> m_model = nullptr;
	std::shared_ptr<IConfig> m_assetConfig = nullptr;
	std::shared_ptr<IController> m_controller = nullptr;

	// Widgets
	QWidget* playground = new QWidget;
	QVBoxLayout* playgroundLayout = new QVBoxLayout;
	QWidget* deck = new QWidget;
	QVBoxLayout* deckLayout = new QVBoxLayout;
	QWidget* hiddenCards = new QWidget;
	QHBoxLayout* hiddenCardsLayout = new QHBoxLayout;
	QPushButton* proceedPushButton = new QPushButton;
	QPushButton* drawCardPushButton = new QPushButton;
	QLabel* closedCardLabel = new QLabel;
	QLabel* openedCardLabel = new QLabel;
	QWidget* diamondWidget = new QWidget;
	QHBoxLayout* diamondLayout = new QHBoxLayout;
	QWidget* heartWidget = new QWidget;
	QHBoxLayout* heartLayout = new QHBoxLayout;
	QWidget* spadeWidget = new QWidget;
	QHBoxLayout* spadeLayout = new QHBoxLayout;
	QWidget* clubWidget = new QWidget;
	QHBoxLayout* clubLayout = new QHBoxLayout;
};

#endif // Q_GAME_WIDGET_H
