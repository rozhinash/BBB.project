/********************************************************************************
** Form generated from reading UI file 'user.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_H
#define UI_USER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_User
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *User)
    {
        if (User->objectName().isEmpty())
            User->setObjectName("User");
        User->resize(800, 600);
        centralwidget = new QWidget(User);
        centralwidget->setObjectName("centralwidget");
        User->setCentralWidget(centralwidget);
        menubar = new QMenuBar(User);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        User->setMenuBar(menubar);
        statusbar = new QStatusBar(User);
        statusbar->setObjectName("statusbar");
        User->setStatusBar(statusbar);

        retranslateUi(User);

        QMetaObject::connectSlotsByName(User);
    } // setupUi

    void retranslateUi(QMainWindow *User)
    {
        User->setWindowTitle(QCoreApplication::translate("User", "User", nullptr));
    } // retranslateUi

};

namespace Ui {
    class User: public Ui_User {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_H
