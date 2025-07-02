#ifndef USER_H
#define USER_H
#include <QWidget>
#include <QString>
#include <QLineEdit>
#include <QPushButton>
#include "../Role/role.h"
class User : public QWidget{
    Q_OBJECT

//private :
protected:
    Role userLevel;
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
    //explicit User(QWidget *parent = nullptr);
   User( int userID , QString name , QString lastname ,  QString password , Role level , QWidget*parent = nullptr);
   virtual void setupUI(); //تنظیم یو ای
    void registerUser();
    void saveToDatabase();
    void updateProfile();
    virtual bool login(const QString& name , const QString& lastname , const QString& password);
};
#endif
