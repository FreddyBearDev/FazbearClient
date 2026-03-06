#include "gamespage.h"
#include "core/gamemanager.h"

#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QPixmap>

GamesPage::GamesPage(QWidget *parent)
    : QWidget(parent)
{
}

void GamesPage::loadGames()
{
    GameManager manager;

    QVector<GameInfo> games = manager.loadGames("games");

    QGridLayout *grid = findChild<QGridLayout*>("gridLayout_games");

    int row = 0;
    int col = 0;

    for(const GameInfo &game : games)
    {
        QWidget *card = new QWidget();
        QVBoxLayout *layout = new QVBoxLayout(card);

        QLabel *icon = new QLabel();

        if(!game.icon.isEmpty())
            icon->setPixmap(QPixmap(game.icon).scaled(64,64));

        QLabel *name = new QLabel(game.name);

        layout->addWidget(icon);
        layout->addWidget(name);

        grid->addWidget(card,row,col);

        col++;

        if(col == 3)
        {
            col = 0;
            row++;
        }
    }
}