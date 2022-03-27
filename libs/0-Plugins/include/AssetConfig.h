#ifndef ASSET_CONFIG_H
#define ASSET_CONFIG_H

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

#endif // ASSET_CONFIG_H
