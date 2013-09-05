#include <QApplication>
#include <QDebug>
#include "mainwidget.h"
#include <QStyle>
#include <QCommonStyle>
#include <QStyleFactory>

#include "threadtest.h"
#include <QLCDNumber>
#include "tcptest.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget* w = new MainWidget;
    w->show();

    a.setOrganizationName("orgname");
    a.setApplicationName("app");
    return a.exec();
}
