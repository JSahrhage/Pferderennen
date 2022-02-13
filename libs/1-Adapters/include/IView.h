#ifndef I_VIEW_H
#define I_VIEW_H

// Project Includes
#include "Model.h"

class IView
{
public:
    virtual ~IView() {}
    virtual void setModel(std::shared_ptr<Model> model) = 0;
    virtual void render() = 0;
};

#endif // I_VIEW_H
