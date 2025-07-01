/********************************************************************************
** Form generated from reading UI file 'adminwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWIDGET_H
#define UI_ADMINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminwidget
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *btnAddUser;
    QPushButton *btnRemoveUser;
    QPushButton *btnEditUser;
    QLabel *labelTitle;

    void setupUi(QWidget *adminwidget)
    {
        if (adminwidget->objectName().isEmpty())
            adminwidget->setObjectName("adminwidget");
        adminwidget->resize(1472, 668);
        verticalLayout = new QVBoxLayout(adminwidget);
        verticalLayout->setObjectName("verticalLayout");
        btnAddUser = new QPushButton(adminwidget);
        btnAddUser->setObjectName("btnAddUser");

        verticalLayout->addWidget(btnAddUser);

        btnRemoveUser = new QPushButton(adminwidget);
        btnRemoveUser->setObjectName("btnRemoveUser");

        verticalLayout->addWidget(btnRemoveUser);

        btnEditUser = new QPushButton(adminwidget);
        btnEditUser->setObjectName("btnEditUser");

        verticalLayout->addWidget(btnEditUser);

        labelTitle = new QLabel(adminwidget);
        labelTitle->setObjectName("labelTitle");

        verticalLayout->addWidget(labelTitle);


        retranslateUi(adminwidget);

        QMetaObject::connectSlotsByName(adminwidget);
    } // setupUi

    void retranslateUi(QWidget *adminwidget)
    {
        adminwidget->setWindowTitle(QCoreApplication::translate("adminwidget", "Form", nullptr));
        btnAddUser->setText(QCoreApplication::translate("adminwidget", "            \330\247\331\201\330\262\331\210\330\257\331\206 \332\251\330\247\330\261\330\250\330\261          ", nullptr));
        btnRemoveUser->setText(QCoreApplication::translate("adminwidget", "\330\255\330\257\331\201 \332\251\330\247\330\261\330\250\330\261", nullptr));
        btnEditUser->setText(QCoreApplication::translate("adminwidget", "\331\210\333\214\330\261\330\247\333\214\330\264 \330\247\330\267\331\204\330\247\330\271\330\247\330\252", nullptr));
        labelTitle->setText(QCoreApplication::translate("adminwidget", "                                                                                                                                                                       \331\205\330\257\333\214\330\261\333\214\330\252 \332\251\330\247\330\261\330\250\330\261\330\247\331\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminwidget: public Ui_adminwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWIDGET_H
