#include "appmanager.h"

AppManager& AppManager::instance()
{
    static AppManager instance;
    return instance;
}

void AppManager::initialize()
{
    // Inicialización futura
}