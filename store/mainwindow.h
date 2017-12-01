#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <forgetpassword.h>
#include <login.h>
#include <signup.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_login_clicked();

    void on_pushButton_2_clicked();

    void on_forget_clicked();

private:
    Ui::MainWindow *ui;
    ForgetPassword *f=new ForgetPassword;
    login *l=new login;
    signup *s=new signup;
};

#endif // MAINWINDOW_H
