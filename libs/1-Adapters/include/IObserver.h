#ifndef I_OBSERVER_H
#define I_OBSERVER_H

class IObserver
{
public:
    virtual ~IObserver() {};
    virtual void update() = 0;
};

#endif // I_OBSERVER_H
