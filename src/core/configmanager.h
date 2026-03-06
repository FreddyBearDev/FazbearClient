#pragma once
#include <QString>

class ConfigManager
{
public:
    static ConfigManager& instance();

    void load();
    void save();

    QString theme() const;
    void setTheme(const QString& theme);

private:
    ConfigManager() = default;

    QString m_theme = "dark";
};