#ifndef I_Q_VIEW_WIDGET_H
#define I_Q_VIEW_WIDGET_H

// C++ Library Includes
#include <memory>

// Qt Includes
#include <QWidget>

// Project Includes
#include "IController.h"

class IQViewWidget : public QWidget
{
public:
    virtual ~IQViewWidget() {}
    virtual void setController(IController* controller) = 0;
    virtual void generateGeneralLayout() = 0;
    virtual void connects() = 0;
    virtual void updateUI() = 0;
};

#endif // I_Q_VIEW_WIDGET_H
