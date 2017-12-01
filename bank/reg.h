#ifndef REG_H
#define REG_H

#include <QDialog>
#include<QMessageBox>
#include <QtSql>
#include <QDebug>
#include <string>
#include <QString>
using namespace std;
namespace Ui {
class reg;
}

class reg : public QDialog
{
    Q_OBJECT

public:
    explicit reg(QWidget *parent = 0);
    ~reg();

private slots:
    void on_back_clicked();

    void on_submit_clicked();

private:
    Ui::reg *ui;
};

#endif // REG_H
