#include "dialog.h"
#include "ui_dialog.h"
#include "titlebar.h"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    wnd = new QDialog(this);

    wnd->setWindowFlags(Qt::FramelessWindowHint|Qt::CustomizeWindowHint);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->setupUi(wnd);
    this->resize(wnd->width(),wnd->height()+20);

    wnd->move(0,20);

    titlebar = new TitleBar(this);
    titlebar->resize(wnd->width(),20);
    titlebar->move(0,0);

}

Dialog::~Dialog()
{
    delete ui;
}
