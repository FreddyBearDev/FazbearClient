#ifndef GAMESPAGE_H
#define GAMESPAGE_H

#include <QWidget>

class GamesPage : public QWidget
{
    Q_OBJECT

public:
    explicit GamesPage(QWidget *parent = nullptr);

    void loadGames();
};

#endif