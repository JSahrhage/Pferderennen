#ifndef I_VIEW_H
#define I_VIEW_H

// C++ Library Includes
#include <memory>

// Project Includes
#include "IController.h"

class IView
{
public:
    virtual ~IView() {}
    virtual void setWidgetController(std::shared_ptr<IController> controller) = 0;
    virtual void render() = 0;
};

#endif // I_VIEW_H
