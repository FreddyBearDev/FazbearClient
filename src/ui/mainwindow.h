#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class HomePage;
class GamesPage;
class WikiPage;
class SettingsPage;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pageHome_customContextMenuRequested(const QPoint &pos);

private:
    Ui::MainWindow *ui;

    HomePage* homePage;
    GamesPage* gamesPage;
    WikiPage* wikiPage;
    SettingsPage* settingsPage;

    void setupPages();
    void setupConnections();
};
