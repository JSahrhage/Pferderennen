#ifndef I_CONTROLLER_H
#define I_CONTROLLER_H

class IController
{
public:
    virtual ~IController() {}
    virtual void onLoad() = 0;
    virtual void printStuff() = 0;
};

#endif // I_CONTROLLER_H
