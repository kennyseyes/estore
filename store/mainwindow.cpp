#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_login_clicked()
{
    this->hide();
    l->show();
    if(l->exec())
        this->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    this->hide();
    s->show();
    if(s->exec())
        this->show();
}

void MainWindow::on_forget_clicked()
{
    this->hide();
    f->show();
    if(f->exec())
        this->show();
}
