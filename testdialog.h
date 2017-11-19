#ifndef TESTDIALOG_H
#define TESTDIALOG_H

#include <ctdialog.h>
namespace Ui {
class TestDialog;
}

class TestDialog : public CTDialog
{
    Q_OBJECT

public:
    explicit TestDialog(QWidget *parent = 0);
    ~TestDialog();


public slots:
    void on_pushButton_clicked();

    void pushButton_2();

private slots:
    void on_buttonBox_accepted();

    
private:
    Ui::TestDialog *ui;
};

#endif // TESTDIALOG_H
