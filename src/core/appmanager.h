#pragma once

class AppManager
{
public:
    static AppManager& instance();

    void initialize();

private:
    AppManager() = default;
};