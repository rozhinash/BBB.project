#include "adminwidget.h"
#include "ui_adminwidget.h"
#include "admin.h"
#include <QMessageBox>


 AdminWidget::AdminWidget(Admin* admin , QWidget* parent)
    :QWidget (parent) ,  ui(new Ui::AdminWidget) , currentAdmin(admin)

{
    ui->setupUi(this);
    //بررسی نقش ادمین و نمایش متن مناسب

     ui->roleLabel->setText (currentAdmin->getRole() ==Role::SuperAdmin ?"Super Admin":"Admin");


    //اتصال دکمه ها به اسلات های مربوطه
    connect (ui->createSessionButton , &QPushButton::clicked , this , &AdminWidget::on_createSessionButton_clicked);
    connect (ui->deleteSessionButton , &QPushButton::clicked , this , &AdminWidget::on_deleteSessionButton_clicked);
    connect (ui->manageUserButton , &QPushButton::clicked , this , &AdminWidget::on_manageUserButton_clicked);
}


AdminWidget::~AdminWidget() {
    delete ui;
}
void AdminWidget::on_createSessionButton_clicked() {
    QMessageBox::information(this , "اطلاعیه" , "جلسه ایجاد شد");
}
 void AdminWidget::on_deleteSessionButton_clicked  (){
     QMessageBox::information(this , "اطلاعیه" , "جلسه حذف شد");

}

 void AdminWidget::on_manageUserButton_clicked() {
     if (currentAdmin->getRole() ==Role::SuperAdmin)
         QMessageBox::information(this , "مدیریت" , "مدیریت کاربر موفق بود");
     else
         QMessageBox::warning(this , "خطا " , "شما دسترسی لازم ندارید");
 }
