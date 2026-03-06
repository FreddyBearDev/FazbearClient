#ifndef GAMESPAGE_H
#define GAMESPAGE_H

#include <QWidget>

namespace Ui {
class GamesPage;
}

class GamesPage : public QWidget
{
    Q_OBJECT

public:
    explicit GamesPage(QWidget *parent = nullptr);
    void loadGames();

private:
    Ui::GamesPage *ui;
};

#endif