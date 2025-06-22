#ifndef USER_H
#define USER_H

#include <QWidget>
#include <QString>
#include <QLineEdit>
#include <QPushButton>

class User : public QWidget{
    Q_OBJECT

private :
    int userID;
    QString name;
    QString lastname;
    QString password;

    //ویچت های رابط کرافیکس
    QLineEdit *lineEdit_nathinalID;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_lastname;
    QLineEdit *lineEdit_password;
    QPushButton *btn_register;
    QPushButton *btn_save;

public:
    explicit User(QWidget *parent = nullptr);
    void setupUI(); //تنظیم یو ای
    void registerUser();
    void saveToDatabase();
    void updateProfile();
};
#endif
