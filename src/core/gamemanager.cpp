#include "gamemanager.h"

#include <QDir>
#include <QFileInfoList>

QVector<GameInfo> GameManager::loadGames(QString gamesPath)
{
    QVector<GameInfo> games;

    QDir gamesDir(gamesPath);

    QFileInfoList folders = gamesDir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);

    for (auto folder : folders)
    {
        QDir gameDir(folder.absoluteFilePath());

        GameInfo game;
        game.folder = folder.fileName();

        QFileInfoList files = gameDir.entryInfoList();

        for (auto file : files)
        {
            QString name = file.fileName();

            if (name.endsWith(".exe"))
                game.exePath = file.absoluteFilePath();

            if (name.contains("banner"))
                game.banner = file.absoluteFilePath();

            if (name.contains("icon"))
                game.icon = file.absoluteFilePath();
        }

        game.name = game.folder;

        games.push_back(game);
    }

    return games;
}