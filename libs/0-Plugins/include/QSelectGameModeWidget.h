#ifndef Q_SELECT_GAME_MODE_WIDGET_H
#define Q_SELECT_GAME_MODE_WIDGET_H

// C++ Library Includes
#include <memory>

// Qt Includes
#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>

// Project Includes
#include "IController.h"

class QSelectGameModeWidget : public QWidget
{
	Q_OBJECT

Q_SIGNALS:

public:
	explicit QSelectGameModeWidget(QWidget* parent = nullptr);
	~QSelectGameModeWidget();

	void setController(std::shared_ptr<IController> controller);

private:
	void Connects();

	void GenerateGeneralLayout();

	void printStuff();

private:
	std::shared_ptr<IController> m_controller = nullptr;
};

#endif // Q_SELECT_GAME_MODE_WIDGET_H
