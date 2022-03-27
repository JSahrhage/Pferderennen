#ifndef I_CONTROLLER_H
#define I_CONTROLLER_H

// C++ Library Includes
#include <string>
#include <vector>
#include <tuple>

class IController
{
public:
    virtual ~IController() {}
    virtual void onLoad() = 0;
    virtual void classicModePushButtonClicked() = 0;
    virtual void advancedModePushButtonClicked() = 0;
    virtual void enterPlayerProceedButtonClicked(const std::vector<std::string>& players) = 0;
    virtual void placeBetsChooseGameModeButtonClicked() = 0;
    virtual void placeBetsEnterPlayerButtonClicked() = 0;
    virtual void placeBetsProceedButtonClicked(const std::vector<std::tuple<std::string, std::string, int>>& bets) = 0;
    virtual void gameDrawButtonClicked() = 0;
    virtual void gameProceedButtonClicked() = 0;
};

#endif // I_CONTROLLER_H
