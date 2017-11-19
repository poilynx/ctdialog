#include "innerdialog.h"
#include <ctdialog.h>
#include <titlebar.h>
#include <QMessageBox>
InnerDialog::InnerDialog(CTDialog *parent) :
    QDialog(parent)
{
    Q_ASSERT(parent);
    dialog = parent;

}

InnerDialog::~InnerDialog()
{

}


void InnerDialog::resize(int w,int h)
{
    this->dialog->resize(w
                           +this->dialog->contentsMargins().left()
                           +this->dialog->contentsMargins().right()
                           ,
                 h+this->dialog->contentsMargins().top()
                           +this->dialog->contentsMargins().bottom()
                           +this->dialog->titleBar()->height()

                 );

    //this->dialog->resize(w,h);
    //this->QDialog::resize(w,h);
}

void InnerDialog::setMaximumSize(int maxw, int maxh) {
    this->dialog->setMaximumSize(maxw
                                 +this->dialog->contentsMargins().left()
                                 +this->dialog->contentsMargins().right(),
                            maxh
                                 +this->dialog->contentsMargins().top()
                                    +this->dialog->contentsMargins().bottom()
                                    +this->dialog->titleBar()->height());
}
