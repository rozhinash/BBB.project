#include "dashboard.h"
#include <QApplication>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMainWindow w;
    Dashboard *dashboard = new Dashboard;
    w.setCentralWidget(dashboard); // تنظیم داشبورد به عنوان محتوای اصلی
    w.resize(400, 300);
    w.show();

    return a.exec();
}
