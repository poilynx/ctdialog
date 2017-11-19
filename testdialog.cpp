#include "testdialog.h"
#include "ui_testdialog.h"
#include "innerdialog.h"
#include <QMessageBox>
TestDialog::TestDialog(QWidget *parent) :
    CTDialog(parent),
    ui(new Ui::TestDialog)
{
    ui->setupUi(this->clientWnd());
    connect(this->ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(pushButton_2()));
    connect(this->ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_clicked()));

    connect(this->ui->buttonBox,SIGNAL(accepted()),this,SLOT(accept()));
    //setMinimumSize(100,100);
}

TestDialog::~TestDialog()
{
    delete ui;
}

void TestDialog::on_pushButton_clicked()
{

    qDebug("button clicked");
    qDebug(this->isMaximized()?"1":"2");
}

void TestDialog::pushButton_2()
{
    QMessageBox::information(this,"消息","你点我了");
}

void TestDialog::on_buttonBox_accepted()
{
    this->accept();
}


