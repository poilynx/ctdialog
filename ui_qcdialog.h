/********************************************************************************
** Form generated from reading UI file 'qcdialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QCDIALOG_H
#define UI_QCDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QCDialog
{
public:
    QGridLayout *gridLayout;
    QGridLayout *glClient;
    QWidget *widgetToolBar;
    QHBoxLayout *horizontalLayout;
    QLabel *lblTitle;
    QSpacerItem *horizontalSpacer;
    QToolButton *tbMinimize;
    QToolButton *tbMaximize;
    QToolButton *tbClose;

    void setupUi(QDialog *QCDialog)
    {
        if (QCDialog->objectName().isEmpty())
            QCDialog->setObjectName(QString::fromUtf8("QCDialog"));
        QCDialog->resize(472, 259);
        gridLayout = new QGridLayout(QCDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setVerticalSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        glClient = new QGridLayout();
        glClient->setObjectName(QString::fromUtf8("glClient"));
        glClient->setContentsMargins(5, 0, 5, 5);

        gridLayout->addLayout(glClient, 1, 0, 1, 1);

        widgetToolBar = new QWidget(QCDialog);
        widgetToolBar->setObjectName(QString::fromUtf8("widgetToolBar"));
        widgetToolBar->setMinimumSize(QSize(0, 40));
        widgetToolBar->setMaximumSize(QSize(16777215, 40));
        widgetToolBar->setMouseTracking(true);
        widgetToolBar->setStyleSheet(QString::fromUtf8("background-color: rgb(125, 255, 99);"));
        horizontalLayout = new QHBoxLayout(widgetToolBar);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(5, 5, 5, 0);
        lblTitle = new QLabel(widgetToolBar);
        lblTitle->setObjectName(QString::fromUtf8("lblTitle"));

        horizontalLayout->addWidget(lblTitle);

        horizontalSpacer = new QSpacerItem(311, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        tbMinimize = new QToolButton(widgetToolBar);
        tbMinimize->setObjectName(QString::fromUtf8("tbMinimize"));

        horizontalLayout->addWidget(tbMinimize);

        tbMaximize = new QToolButton(widgetToolBar);
        tbMaximize->setObjectName(QString::fromUtf8("tbMaximize"));

        horizontalLayout->addWidget(tbMaximize);

        tbClose = new QToolButton(widgetToolBar);
        tbClose->setObjectName(QString::fromUtf8("tbClose"));

        horizontalLayout->addWidget(tbClose);


        gridLayout->addWidget(widgetToolBar, 0, 0, 1, 1);


        retranslateUi(QCDialog);

        QMetaObject::connectSlotsByName(QCDialog);
    } // setupUi

    void retranslateUi(QDialog *QCDialog)
    {
        QCDialog->setWindowTitle(QApplication::translate("QCDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        lblTitle->setText(QApplication::translate("QCDialog", "Title", 0, QApplication::UnicodeUTF8));
        tbMinimize->setText(QApplication::translate("QCDialog", "\344\270\200", 0, QApplication::UnicodeUTF8));
        tbMaximize->setText(QApplication::translate("QCDialog", "\345\217\243", 0, QApplication::UnicodeUTF8));
        tbClose->setText(QApplication::translate("QCDialog", "\344\271\202", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QCDialog: public Ui_QCDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QCDIALOG_H
