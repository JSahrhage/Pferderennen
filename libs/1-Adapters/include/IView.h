#ifndef I_VIEW_H
#define I_VIEW_H

// Project Includes
#include "IObserver.h"
#include "IController.h"

class IView : public IObserver
{
public:
    virtual ~IView() {}
    virtual void setController(IController* controller) = 0;
};

#endif // I_VIEW_H
