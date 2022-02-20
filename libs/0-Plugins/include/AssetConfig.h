#ifndef CONTROLLER_H
#define CONTROLLER_h

// C++ Library Includes
#include <string>

// Project Includes
#include "IConfig.h"

class AssetConfig : public IConfig
{
public:
    AssetConfig(std::string path) : m_pathToAssets(path) {}

    std::string getPathToAssets() { return this->m_pathToAssets; }

private:
    std::string m_pathToAssets;
};

#endif // CONTROLLER_H
