#include "adminwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Admin* admin = new Admin("Narges", "1385" , Admin::Role::SuperAdmin);

    AdminWidget w(admin);
    w.show();
    return app.exec();
}
