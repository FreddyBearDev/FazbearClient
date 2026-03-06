#include "gamespage.h"
#include "ui_gamespage.h"
#include "core/gamemanager.h"

#include <QGridLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>

GamesPage::GamesPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GamesPage)
{
    ui->setupUi(this);

    loadGames();
}

void GamesPage::loadGames()
{
    QGridLayout *grid = ui->gridLayout_games;

    if(!grid)
        return;

    QVector<GameInfo> games = GameManager::loadGames("games");

    int row = 0;
    int col = 0;

    for(const GameInfo &game : games)
    {
        QWidget *card = new QWidget();
        QVBoxLayout *layout = new QVBoxLayout(card);

        QLabel *icon = new QLabel();
        icon->setPixmap(QPixmap(game.icon).scaled(150,80,Qt::KeepAspectRatio));

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