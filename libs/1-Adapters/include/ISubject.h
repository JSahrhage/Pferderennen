#ifndef I_SUBJECT_H
#define I_SUBJECT_H

// C++ Library Includes
#include <memory>

// Project Includes
#include "IObserver.h"

class ISubject
{
public:
    virtual ~ISubject() {};
    virtual void attach(std::shared_ptr<IObserver> observer) = 0;
    virtual void detach(std::shared_ptr<IObserver> observer) = 0;
    virtual void notify() = 0;
};

#endif // I_SUBJECT_H
