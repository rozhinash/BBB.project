#include "user.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    User userWidget;
    userWidget.show();
    return app.exec();
}
