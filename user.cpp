#include "user.h"
#include <QFormLayout>
#include <QDebug>

User::User (QWidget *parent) : QWidget(parent)
{
    setupUI();
}
void User::setupUI(){

    QFormLayout *layout = new QFormLayout(this);

    lineEdit_nathinalID= new QLineEdit(this);
    lineEdit_name = new QLineEdit (this);
    lineEdit_lastname = new QLineEdit (this);
    lineEdit_password = new QLineEdit (this);
    lineEdit_password -> setEchoMode(QLineEdit::Password); //تمایش رمز عبور مخفی

    btn_register = new QPushButton("ثبت نام" , this);
    btn_save = new QPushButton ("ذخیره" , this);

    layout-> addRow("کد ملی ", lineEdit_nathinalID);
    layout-> addRow ("نام", lineEdit_name);
    layout-> addRow ("نام خوانوادگی", lineEdit_lastname);
    layout-> addRow ("رمز عبور" , lineEdit_password);
    layout-> addRow (btn_register);
    layout-> addRow (btn_save);

    connect (btn_register  , &QPushButton::clicked , this , & User::registerUser);
    connect (btn_save , &QPushButton::clicked , this , &User::saveToDatabase);
}

void User::registerUser()
{
    name = lineEdit_name ->text();
    lastname = lineEdit_lastname ->text();
    password = lineEdit_password ->text();

    qDebug() <<"کاربر ثبت شد:"<<name<<lastname;
}

void User::saveToDatabase()
{
    qDebug() <<"اطلاعات ذخیره شد!";
}

void User::updateProfile()
{
    name = lineEdit_name->text();
    lastname = lineEdit_lastname->text();

    qDebug() <<"پروفایل به روز رسانی شد."<<name<<lastname;
}
