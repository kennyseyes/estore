#ifndef PRODUCTDETAILS_H
#define PRODUCTDETAILS_H

#include <QWidget>

namespace Ui {
class productDetails;
}

class productDetails : public QWidget
{
    Q_OBJECT

public:
    explicit productDetails(QWidget *parent = 0);
    ~productDetails();

private:
    Ui::productDetails *ui;
};

#endif // PRODUCTDETAILS_H
