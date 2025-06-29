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

    btn_save = new QPushButton ("ثبت نام" , this);
    btn_register = new QPushButton("ورود به حساب" , this);

    layout-> addRow ("نام", lineEdit_name);
    layout-> addRow ("نام خوانوادگی", lineEdit_lastname);
    layout-> addRow("کد ملی ", lineEdit_nathinalID);
    layout-> addRow ("رمز عبور" , lineEdit_password);
    layout-> addRow (btn_save);
    layout-> addRow (btn_register);


    btn_register->setStyleSheet("background-color: blue; color: white;");
    btn_save->setStyleSheet("background-color: green; color: white;");

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

    QString nationalID = lineEdit_nathinalID->text().trimmed();
    QString name = lineEdit_name->text().trimmed();
    QString lastname = lineEdit_lastname->text().trimmed();
    QString password = lineEdit_password->text();

    if (nationalID.isEmpty() || name.isEmpty() || lastname.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "هشدار", "لطفاً همه‌ی فیلدها را پر کنید.");
        return;
    }

    // اتصال به پایگاه داده
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("users.db");

    if (!db.open()) {
        QMessageBox::critical(this, "خطا", "اتصال به پایگاه داده برقرار نشد:\n" + db.lastError().text());
        return;
    }

    QSqlQuery query;
    QString createTable = R"(
        CREATE TABLE IF NOT EXISTS users (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            national_id TEXT UNIQUE,
            name TEXT,
            lastname TEXT,
            password TEXT
        )
    )";
    if (!query.exec(createTable)) {
        QMessageBox::critical(this, "خطا", "ایجاد جدول ناموفق بود:\n" + query.lastError().text());
        db.close();
        return;
    }

    // درج اطلاعات در جدول
    query.prepare("INSERT INTO users (national_id, name, lastname, password) VALUES (?, ?, ?, ?)");
    query.addBindValue(nationalID);
    query.addBindValue(name);
    query.addBindValue(lastname);
    query.addBindValue(password);

    if (!query.exec()) {
        QMessageBox::critical(this, "خطا", "ذخیره‌سازی اطلاعات ناموفق بود:\n" + query.lastError().text());
    } else {
        QMessageBox::information(this, "موفق", "اطلاعات با موفقیت ذخیره شد.");
        qDebug() << "اطلاعات ذخیره شد:" << name << lastname;
    }

    db.close();
}

void User::updateProfile()
{
    name = lineEdit_name->text();
    lastname = lineEdit_lastname->text();

    qDebug() <<"پروفایل به روز رسانی شد."<<name<<lastname;
}
