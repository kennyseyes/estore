#ifndef USER_H
#define USER_H

#include <QDialog>
#include<QWheelEvent>
#include <QtSql>

namespace Ui {
class user;
}

class user : public QDialog
{
    Q_OBJECT

public:
    explicit user(QWidget *parent = 0);
    ~user();

private slots:


    void on_pushButton_clicked();

    void on_MaleCLothes_clicked();

    void on_FemaleClothes_clicked();

    void on_Shoes_clicked();

    void on_Snacks_clicked();

    void on_Health_clicked();

    void on_Fruits_clicked();

    void on_Novel_clicked();

    void on_Edu_clicked();

    void on_Tools_clicked();

    void on_PC_clicked();

    void on_Camera_clicked();

    void on_Elc_clicked();

    void on_Equipment_clicked();

    void on_SportsCLothes_clicked();

    void on_SportShoes_clicked();

    void setProducts(QString type);

    void on_mainpage_clicked();

private:
    Ui::user *ui;
};

#endif // USER_H
