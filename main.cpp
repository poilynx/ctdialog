#include "dialog.h"
#include <QApplication>
#include <ctdialog.h>
#include <testdialog.h>
#include <QMessageBox>
#include <innerdialog.h>
#include <QTextEncoder>
#include <QFontDatabase>
int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QApplication a(argc, argv);
    int fontId = QFontDatabase::addApplicationFont("ztgj.ttf");
    if(fontId >=0) {
        qDebug("font id:%d\n",fontId);
        QString msyh = QFontDatabase::applicationFontFamilies ( fontId ).at(0);
        QFont font(msyh,10);
        //将此字体设为QApplication的默认字体
        QApplication::setFont(font);
    }
    

    TestDialog dialog;
    dialog.setWindowTitle("这是一段特别特别长的测试窗口标题栏文本的字符串");
    dialog.exec();
    return 0;
}
