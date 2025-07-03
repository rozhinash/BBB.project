#include <QApplication>
#include "regularuser.h"
#include "../Role/role.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    RegularUser* regUser = new RegularUser(1234, "نرگس", "میرزایی", "pass2323", Role::Regular);
    regUser->joinSession("جلسه‌ی ای پی");
    regUser->joinSession("جلسه‌ی هک و امنیت");
    regUser->leaveSession("جلسه دوم ای پی");
    regUser->show(); // نمایش فرم ورودی و دکمهٔ تاریخچه

    return a.exec();
}
