#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QtSql>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMessageBox msg;


//连接数据库
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("store");
    db.setUserName("root");
    db.setPassword("123456");

    if(db.open()){
        QMessageBox::about(NULL, "Success", "Database connected successfuly.");

        MainWindow w;
        w.show();
        return a.exec();
        db.close();
    }

    else{
        QMessageBox::about(NULL, "Error", "Failed to connect database, please try again.");
        return a.exec();
    }
}
