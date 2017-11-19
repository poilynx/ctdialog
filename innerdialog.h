#ifndef INNERDIALOG_H
#define INNERDIALOG_H

#include <QDialog>

class CTDialog;
class InnerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InnerDialog(CTDialog *parent = 0);
    ~InnerDialog();
    void resize(const QSize &size) {
        resize(size.width(),size.height());
    }

    void resize(int w, int h);
    void setMaximumSize(int maxw, int maxh);
    void setMaximumSize(const QSize &s) {
        setMaximumSize(s.width(), s.height());
    }

private:
    CTDialog * dialog;

};

#endif // INNERDIALOG_H
