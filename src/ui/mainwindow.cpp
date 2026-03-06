#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopServices>
#include <QUrl>
#include "pages/homepage.h"
#include "pages/gamespage.h"
#include "pages/wikipage.h"
#include "pages/settingspage.h"
#include "core/gamemanager.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setupPages();
    setupConnections();

    // Video 1
    connect(ui->btnThumb1, &QPushButton::clicked, this, []() {
        QDesktopServices::openUrl(
            QUrl("https://www.youtube.com/watch?v=cX96IudVW2o"));
    });

    // Video 2
    connect(ui->btnThumb2, &QPushButton::clicked, this, []() {
        QDesktopServices::openUrl(
            QUrl("https://www.youtube.com/watch?v=gk-aCL6eyGc"));
    });

    // Video 3
    connect(ui->btnThumb3, &QPushButton::clicked, this, []() {
        QDesktopServices::openUrl(
            QUrl("https://www.youtube.com/watch?v=c5ExAgZmUw8"));
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupPages()
{
    homePage = new HomePage(this);
    gamesPage = new GamesPage(this);
    wikiPage = new WikiPage(this);
    settingsPage = new SettingsPage(this);

    ui->stackedWidget->addWidget(homePage);
    ui->stackedWidget->addWidget(gamesPage);
    ui->stackedWidget->addWidget(wikiPage);
    ui->stackedWidget->addWidget(settingsPage);

    ui->stackedWidget->setCurrentIndex(0);

    gamesPage->loadGames();
}

void MainWindow::setupConnections()
{
    connect(ui->btnHome, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(0);
    });

    connect(ui->btnGames, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(1);
    });

    connect(ui->btnWiki, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(2);
    });

    connect(ui->btnSettings, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(3);
    });
}

void MainWindow::on_pageHome_customContextMenuRequested(const QPoint &pos)
{

}

