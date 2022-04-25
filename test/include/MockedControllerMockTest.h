#ifndef MOCKED_CONTROLLER_MOCK_TEST_H
#define MOCKED_CONTROLLER_MOCK_TEST_H

// C++ Library Includes
#include <string>
#include <vector>
#include <tuple>

// GoogleTest
#include <gmock/gmock.h>
#include "gmock/gmock.h"
#include <gtest/gtest.h>

// Project Includes
#include "IController.h"

class MockController : public IController
{
public:
    MOCK_METHOD(void, onLoad, (), (override));
    MOCK_METHOD(void, classicModePushButtonClicked, (), (override));
    MOCK_METHOD(void, advancedModePushButtonClicked, (), (override));
    MOCK_METHOD(void, enterPlayerProceedButtonClicked, (const std::vector<std::string>& players), (override));
    MOCK_METHOD(void, placeBetsChooseGameModeButtonClicked, (), (override));
    MOCK_METHOD(void, placeBetsEnterPlayerButtonClicked, (), (override));
    MOCK_METHOD(void, placeBetsProceedButtonClicked, ((const std::vector<std::tuple<std::string, std::string, int>>& bets)), (override));
    MOCK_METHOD(void, gameDrawButtonClicked, (), (override));
    MOCK_METHOD(void, gameProceedButtonClicked, (), (override));
    MOCK_METHOD(void, distributeSipsProceedButtonClicked, (), (override));
};

#endif  // MOCKED_CONTROLLER_MOCK_TEST_H
