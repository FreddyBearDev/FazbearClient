#pragma once

#include <QString>
#include <QVector>

struct GameInfo
{
    QString name;
    QString exePath;
    QString banner;
    QString icon;
    QString folder;
};

class GameManager
{
public:
    static QVector<GameInfo> loadGames(QString gamesPath);
};