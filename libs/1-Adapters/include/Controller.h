#ifndef CONTROLLER_H
#define CONTROLLER_h

// C++ Library Includes
#include <memory>

// Project Includes
#include "IController.h"
#include "Model.h"
#include "IView.h"

class Controller : public IController
{
public:
    Controller(std::shared_ptr<Model> model, std::shared_ptr<IView> view);
    void onLoad();

    void classicModePushButtonClicked();

    void advancedModePushButtonClicked();

    void enterPlayerProceedButtonClicked(const std::vector<std::string>& player);

    void placeBetsChooseGameModeButtonClicked();

    void placeBetsEnterPlayerButtonClicked();

    void placeBetsProceedButtonClicked(const std::vector<std::tuple<std::string, std::string, int>>& bets);

    void gameDrawButtonClicked();

    void gameProceedButtonClicked();

    void distributeSipsProceedButtonClicked();

private:
    std::shared_ptr<Model> m_model = nullptr;
    std::shared_ptr<IView> m_view = nullptr;
};

#endif // CONTROLLER_H
