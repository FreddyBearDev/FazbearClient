#pragma once

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class WikiPage; }
QT_END_NAMESPACE

class WikiPage : public QWidget
{
    Q_OBJECT

public:
    explicit WikiPage(QWidget *parent = nullptr);
    ~WikiPage();

private:
    Ui::WikiPage *ui;
};