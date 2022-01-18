// Project Includes
#include "QtPlugin.h"

// Qt Includes
#include "QApplication"

QtPlugin::QtPlugin(int argc, char* argv[])
{

}

void QtPlugin::runApp(int argc, char* argv[])
{
    QApplication app = QApplication(argc, argv);
}
