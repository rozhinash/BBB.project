#ifndef ADMINWIDGET_H
#define ADMINWIDGET_H
#include <QWidget>
#include "admin.h"
QT_BEGIN_NAMESPACE
namespace Ui{ class AdminWidget;}
QT_END_NAMESPACE


class AdminWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AdminWidget(Admin *admin , QWidget* parent = nullptr);
    ~AdminWidget();

private slots:
    void on_createSessionButton_clicked();
    void on_deleteSessionButton_clicked();
    void on_manageUserButton_clicked();

private:
    Ui::AdminWidget *ui;
    Admin* currentAdmin;
};

#endif// ADMINWIDGET_H
