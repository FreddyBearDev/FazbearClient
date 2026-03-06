#include "gamespage.h"
#include "core/gamemanager.h"

#include <QGridLayout>
#include <QLabel>
#include <QVBoxLayout>
#include <QPixmap>

GamesPage::GamesPage(QWidget *parent)
    : QWidget(parent)
{
    loadGames();   // ← IMPORTANTE: esto carga los juegos al abrir la página
}

void GamesPage::loadGames()
{
    // Busca el grid dentro del .ui
    QGridLayout *grid = findChild<QGridLayout*>("gridLayout_games");

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
        icon->setPixmap(QPixmap(game.icon).scaled(120,120));

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