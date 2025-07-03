#include <QApplication>
#include "timetracker.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    TimeTracker tracker;
    tracker.show(); // اگه نمی‌خوای پنجره نشون داده بشه، این خط رو حذف کن

    return app.exec();
}
