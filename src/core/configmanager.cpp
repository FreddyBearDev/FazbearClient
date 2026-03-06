#include "configmanager.h"

ConfigManager& ConfigManager::instance()
{
    static ConfigManager instance;
    return instance;
}

void ConfigManager::load()
{
    // Aquí luego leeremos JSON
}

void ConfigManager::save()
{
    // Aquí luego guardaremos JSON
}

QString ConfigManager::theme() const
{
    return m_theme;
}

void ConfigManager::setTheme(const QString& theme)
{
    m_theme = theme;
}