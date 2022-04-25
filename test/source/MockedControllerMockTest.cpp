// C++ Library Includes
#include <memory>

// Test Includes
#include "MockedControllerMockTest.h"

// Project Includes
#include "AssetConfig.h"
#include "SizeConfig.h"
#include "QGameWidget.h"

// Qt Includes
#include "QApplication"

using ::testing::AtLeast;

TEST(QGameWidgetTest, MockedControllerMockTest) {
    MockController controller;

    EXPECT_CALL(controller, gameDrawButtonClicked()).Times(AtLeast(1));

    std::shared_ptr<AssetConfig> assetConfig = std::make_shared<AssetConfig>(AssetConfig("../../src/assets"));
    std::shared_ptr<SizeConfig> sizeConfig = std::make_shared<SizeConfig>(SizeConfig(192, 128));
    std::shared_ptr<Model> model = std::make_shared<Model>(Model());

    char arg0[] = "programName";
    char* argv[] = { &arg0[0], NULL };
    int argc = (int)(sizeof(argv) / sizeof(argv[0])) - 1;

    QApplication application = QApplication(argc, & argv[0]);
    QGameWidget gameWidget = QGameWidget(model, assetConfig, sizeConfig);
    gameWidget.setController(&controller);

    gameWidget.drawButtonClicked();

    ASSERT_EQ(1, 1);
}
