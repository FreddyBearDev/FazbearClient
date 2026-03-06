#include "wikipage.h"
#include "ui_wikipage.h"

WikiPage::WikiPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WikiPage)
{
    ui->setupUi(this);
}

WikiPage::~WikiPage()
{
    delete ui;
}