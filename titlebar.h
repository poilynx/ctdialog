#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>
#include <ctdialog.h>
namespace Ui {
class TitleBar;
}

class TitleBar : public QWidget
{
    Q_OBJECT

public:
    explicit TitleBar(CTDialog *dialog);
    ~TitleBar();
    void setTitle(const QString &title);
    QString getTitle();
private slots:
    void on_tbMinimize_clicked();

    void on_tbMaximize_clicked();

    void on_tbClose_clicked();
protected:
    void mousePressEvent(QMouseEvent *me);

    void mouseMoveEvent(QMouseEvent *me);
    
    void mouseReleaseEvent(QMouseEvent *me);
    
    void resizeEvent(QResizeEvent *);
    
    void paintEvent(QPaintEvent *pe);
    
    void showEvent(QShowEvent *);

private:
    Ui::TitleBar *ui;
    CTDialog *dialog;
    QPoint startPos;
    QPoint clickPos;
    //bool maxNormal;
    bool isDown;
    //QPoint mousePos;
    int x;
    int y;
    bool isMaximizedLastTime;
    void updateUI();
};

#endif // TITLEBAR_H
