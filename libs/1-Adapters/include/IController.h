#ifndef I_CONTROLLER_H
#define I_CONTROLLER_H

// C++ Library Includes
#include <string>
#include <vector>

class IController
{
public:
    virtual ~IController() {}
    virtual void onLoad() = 0;
    virtual void classicModePushButtonClicked() = 0;
    virtual void advancedModePushButtonClicked() = 0;
    virtual void enterPlayerProceedButtonClicked(const std::vector<std::string>& player) = 0;
};

#endif // I_CONTROLLER_H
