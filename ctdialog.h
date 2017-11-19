#ifndef QCDIALOG_H
#define QCDIALOG_H

#include <QDialog>
#include <QMouseEvent>
#include <QLayout>
#include <QTimerEvent>
namespace Ui {
class CTDialog;
}
class TitleBar;
class InnerDialog;
class CTDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CTDialog(QWidget *parent = 0);
    InnerDialog * clientWnd();
    TitleBar *titleBar();
    ~CTDialog();
    void setWindowTitle(const QString &title);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

    void paintEvent(QPaintEvent *e);
    //void timerEvent(QTimerEvent *e);

private slots:



private:
    Ui::CTDialog *ui;
    TitleBar *titlebar;

    InnerDialog *client;
    QGridLayout *layout;
    QWidget *m_content;
    QPoint m_old_pos;
    bool m_mouse_down;
    bool left, right, top, bottom;
    bool isMoving;

};

#endif // QCDIALOG_H
