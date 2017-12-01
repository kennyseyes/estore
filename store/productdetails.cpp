#include "productdetails.h"
#include "ui_productdetails.h"

productDetails::productDetails(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::productDetails)
{
    ui->setupUi(this);
}

productDetails::~productDetails()
{
    delete ui;
}
