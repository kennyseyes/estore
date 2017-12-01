#include "cart.h"
#include "ui_cart.h"

cart::cart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cart)
{
    ui->setupUi(this);
}

cart::~cart()
{
    delete ui;
}
