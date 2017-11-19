#include "titlebar.h"
#include "ui_titlebar.h"

TitleBar::TitleBar(CTDialog *dialog) :
    ui(new Ui::TitleBar)
{
    ui->setupUi(this);
    Q_ASSERT(dialog);
    this->dialog = dialog;
    this->ui->lblTitle->setText(dialog->windowTitle());
    this->setMouseTracking(true);
    //this->maxNormal = false;
    //setCursor(Qt::ArrowCursor);
    //this->isMaximizedLastTime = false;
    //this->ui->tbClose->setStyleSheet("");
    
}

TitleBar::~TitleBar()
{
    delete ui;
}

void TitleBar::setTitle(const QString &title)
{
    this->dialog->QDialog::setWindowTitle(title);
    this->ui->lblTitle->setText(title);
    this->ui->lblTitle->adjustSize();
}

QString TitleBar::getTitle()
{
    return this->dialog->windowTitle();
}

void TitleBar::on_tbMinimize_clicked()
{
    this->dialog->showMinimized();
}

void TitleBar::updateUI()
{
    if(this->dialog->isMaximized()) {
        //maxNormal = false;
        this->ui->tbMaximize->setText("回");
    } else {
        this->ui->tbMaximize->setText("口");
    }
}

void TitleBar::on_tbMaximize_clicked()
{
    if(this->dialog->isMaximized()) {
        this->dialog->showNormal();
    } else {
        this->dialog->showMaximized();
        //this->resize(this->maximumWidth()-1,this->maximumHeight()-1);

    }
    updateUI();
}

void TitleBar::on_tbClose_clicked()
{
    this->dialog->close();


}

void TitleBar::showEvent(QShowEvent *e)
{
    qDebug("show_event()");
}

void TitleBar::paintEvent(QPaintEvent *pe)
{
    if(isMaximizedLastTime && !this->isMaximized()) {
        //qDebug("bug");
        updateUI();
        isMaximizedLastTime = false;
    } else {
        updateUI();
        isMaximizedLastTime = true;
    }
}

void TitleBar::resizeEvent(QResizeEvent *)
{
}

void TitleBar::mouseMoveEvent ( QMouseEvent  * e )
{
#ifdef Q_OS_WIN32
    if(qrand()%5<3) return;
#endif
    setCursor(Qt::ArrowCursor);
    if(isDown)
    {
        this->dialog->move(this->dialog->pos().x()+(e->globalX()-x),this->dialog->pos().y()+(e->globalY()-y));
        x=e->globalX();
        y=e->globalY();
    }
}

void TitleBar::mouseReleaseEvent ( QMouseEvent * e )
{
    if(e->button() == Qt::LeftButton)
    {
        isDown=false;
    }
}

void TitleBar::mousePressEvent ( QMouseEvent * e )
{
    //if (maxNormal)
    //    return;
    qDebug("Press");
    if(this->dialog->isMaximized())
        return;
    if(e->button()==Qt::LeftButton)
    {
        isDown=true;
        x=e->globalX();
        y=e->globalY();
    }

}
