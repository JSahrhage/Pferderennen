// C++ Library Includes
#include <iostream>

// Project Includes
#include "Controller.h"

Controller::Controller(std::shared_ptr<Model> model, std::shared_ptr<IView> view) : m_model(model), m_view(view)
{
    if (model == nullptr)
    {
        throw std::invalid_argument("model must not be null");
    }
    if (view == nullptr)
    {
        throw std::invalid_argument("view must not be null");
    }
}

void Controller::onLoad()
{
    this->m_view->render();
}

void Controller::printStuff()
{
    std::cout << "Stuff" << std::endl;
}
