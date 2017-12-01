#include "user.h"
#include "ui_user.h"
#include <QMessageBox>
#include <QDebug>

QVBoxLayout *vlay1;

user::user(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user)
{
    ui->setupUi(this);
    //connect(ui->verticalScrollBar,SIGNAL(valueChanged(int)),this,SLOT(slot_scrollArea(int)));
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(close()));
    ui->scrollw->hide();
}

user::~user()
{
    delete ui;
}

void user::on_pushButton_clicked()
{
    accept();
}

void user::on_MaleCLothes_clicked()
{
    ui->MainShow->hide();
    ui->scrollw->show();

    delete vlay1;
    QList<QLabel*> lbls = ui->scrollAreaWidgetContents->findChildren<QLabel*>();
    foreach (QLabel* lb, lbls) {   delete lb;  }
    QList<QPushButton*> btns = ui->scrollAreaWidgetContents->findChildren<QPushButton*>();
    foreach (QPushButton* btn, btns) {   delete btn;  }

    QString s="clothes/male";
    setProducts(s);
}

void user::on_FemaleClothes_clicked()
{
    ui->MainShow->hide();
    ui->scrollw->show();

    delete vlay1;
    QList<QLabel*> lbls = ui->scrollAreaWidgetContents->findChildren<QLabel*>();
    foreach (QLabel* lb, lbls) {   delete lb;  }
    QList<QPushButton*> btns = ui->scrollAreaWidgetContents->findChildren<QPushButton*>();
    foreach (QPushButton* btn, btns) {   delete btn;  }

    QString s="clothes/female";
    setProducts(s);
}

void user::on_Shoes_clicked()
{
    ui->MainShow->hide();
    ui->scrollw->show();

    delete vlay1;
    QList<QLabel*> lbls = ui->scrollAreaWidgetContents->findChildren<QLabel*>();
    foreach (QLabel* lb, lbls) {   delete lb;  }
    QList<QPushButton*> btns = ui->scrollAreaWidgetContents->findChildren<QPushButton*>();
    foreach (QPushButton* btn, btns) {   delete btn;  }

    QString s="clothes/shoes";
    setProducts(s);
}

void user::on_Snacks_clicked()
{
    ui->MainShow->hide();
    ui->scrollw->show();

    delete vlay1;
    QList<QLabel*> lbls = ui->scrollAreaWidgetContents->findChildren<QLabel*>();
    foreach (QLabel* lb, lbls) {   delete lb;  }
    QList<QPushButton*> btns = ui->scrollAreaWidgetContents->findChildren<QPushButton*>();
    foreach (QPushButton* btn, btns) {   delete btn;  }

    QString s="food/snack";
    setProducts(s);
}

void user::on_Health_clicked()
{
    ui->MainShow->hide();
    ui->scrollw->show();

    delete vlay1;
    QList<QLabel*> lbls = ui->scrollAreaWidgetContents->findChildren<QLabel*>();
    foreach (QLabel* lb, lbls) {   delete lb;  }
    QList<QPushButton*> btns = ui->scrollAreaWidgetContents->findChildren<QPushButton*>();
    foreach (QPushButton* btn, btns) {   delete btn;  }

    QString s="food/health";
    setProducts(s);
}

void user::on_Fruits_clicked()
{
    ui->MainShow->hide();
    ui->scrollw->show();

    delete vlay1;
    QList<QLabel*> lbls = ui->scrollAreaWidgetContents->findChildren<QLabel*>();
    foreach (QLabel* lb, lbls) {   delete lb;  }
    QList<QPushButton*> btns = ui->scrollAreaWidgetContents->findChildren<QPushButton*>();
    foreach (QPushButton* btn, btns) {   delete btn;  }

    QString s="food/fruit";
    setProducts(s);
}

void user::on_Novel_clicked()
{
    ui->MainShow->hide();
    ui->scrollw->show();

    delete vlay1;
    QList<QLabel*> lbls = ui->scrollAreaWidgetContents->findChildren<QLabel*>();
    foreach (QLabel* lb, lbls) {   delete lb;  }
    QList<QPushButton*> btns = ui->scrollAreaWidgetContents->findChildren<QPushButton*>();
    foreach (QPushButton* btn, btns) {   delete btn;  }

    QString s="books/novel";
    setProducts(s);
}

void user::on_Edu_clicked()
{
    ui->MainShow->hide();
    ui->scrollw->show();

    delete vlay1;
    QList<QLabel*> lbls = ui->scrollAreaWidgetContents->findChildren<QLabel*>();
    foreach (QLabel* lb, lbls) {   delete lb;  }
    QList<QPushButton*> btns = ui->scrollAreaWidgetContents->findChildren<QPushButton*>();
    foreach (QPushButton* btn, btns) {   delete btn;  }

    QString s="books/edu";
    setProducts(s);
}

void user::on_Tools_clicked()
{
    ui->MainShow->hide();
    ui->scrollw->show();

    delete vlay1;
    QList<QLabel*> lbls = ui->scrollAreaWidgetContents->findChildren<QLabel*>();
    foreach (QLabel* lb, lbls) {   delete lb;  }
    QList<QPushButton*> btns = ui->scrollAreaWidgetContents->findChildren<QPushButton*>();
    foreach (QPushButton* btn, btns) {   delete btn;  }

    QString s="books/tool";
    setProducts(s);

}

void user::on_PC_clicked()
{
    ui->MainShow->hide();
    ui->scrollw->show();

    delete vlay1;
    QList<QLabel*> lbls = ui->scrollAreaWidgetContents->findChildren<QLabel*>();
    foreach (QLabel* lb, lbls) {   delete lb;  }
    QList<QPushButton*> btns = ui->scrollAreaWidgetContents->findChildren<QPushButton*>();
    foreach (QPushButton* btn, btns) {   delete btn;  }

    QString s="elec/pc";
    setProducts(s);
}

void user::on_Camera_clicked()
{
    ui->MainShow->hide();
    ui->scrollw->show();

    delete vlay1;
    QList<QLabel*> lbls = ui->scrollAreaWidgetContents->findChildren<QLabel*>();
    foreach (QLabel* lb, lbls) {   delete lb;  }
    QList<QPushButton*> btns = ui->scrollAreaWidgetContents->findChildren<QPushButton*>();
    foreach (QPushButton* btn, btns) {   delete btn;  }

    QString s="elec/camera";
    setProducts(s);
}

void user::on_Elc_clicked()
{
    ui->MainShow->hide();
    ui->scrollw->show();

    delete vlay1;
    QList<QLabel*> lbls = ui->scrollAreaWidgetContents->findChildren<QLabel*>();
    foreach (QLabel* lb, lbls) {   delete lb;  }
    QList<QPushButton*> btns = ui->scrollAreaWidgetContents->findChildren<QPushButton*>();
    foreach (QPushButton* btn, btns) {   delete btn;  }

    QString s="elec/elc";
    setProducts(s);
}

void user::on_Equipment_clicked()
{
    ui->MainShow->hide();
    ui->scrollw->show();

    delete vlay1;
    QList<QLabel*> lbls = ui->scrollAreaWidgetContents->findChildren<QLabel*>();
    foreach (QLabel* lb, lbls) {   delete lb;  }
    QList<QPushButton*> btns = ui->scrollAreaWidgetContents->findChildren<QPushButton*>();
    foreach (QPushButton* btn, btns) {   delete btn;  }

    QString s="sports/equip";
    setProducts(s);
}

void user::on_SportsCLothes_clicked()
{
    ui->MainShow->hide();
    ui->scrollw->show();

    delete vlay1;
    QList<QLabel*> lbls = ui->scrollAreaWidgetContents->findChildren<QLabel*>();
    foreach (QLabel* lb, lbls) {   delete lb;  }
    QList<QPushButton*> btns = ui->scrollAreaWidgetContents->findChildren<QPushButton*>();
    foreach (QPushButton* btn, btns) {   delete btn;  }

    QString s="sports/spclothes";
    setProducts(s);
}

void user::on_SportShoes_clicked()
{
    ui->MainShow->hide();
    ui->scrollw->show();

    delete vlay1;
    QList<QLabel*> lbls = ui->scrollAreaWidgetContents->findChildren<QLabel*>();
    foreach (QLabel* lb, lbls) {   delete lb;  }
    QList<QPushButton*> btns = ui->scrollAreaWidgetContents->findChildren<QPushButton*>();
    foreach (QPushButton* btn, btns) {   delete btn;  }

    QString s="sports/spshoes";
    setProducts(s);
}

void user::setProducts(QString type)
{
    bool end=false;
    QSqlQuery query;
    query.exec("SELECT * FROM product");
    //载入数据库失败
    if(!query.first())
       QMessageBox::warning(NULL, "Error", "Unable to find \"product\"!", QMessageBox::Ok);
    else
    {
        query.exec(QString("SELECT * FROM product where type='%1'").arg(type)); //选中条目


        if(!query.next())
            qDebug()<<"failed"<<endl;
        else
            qDebug()<<"succeed"<<endl;

        vlay1=new QVBoxLayout();
        while(!end)
        {
            QHBoxLayout *pHLayout1 = new QHBoxLayout();
            for(int i=0;i<3;i++)
            {
                if(query.next())
                {
                    QPixmap image;
                    image.load(query.value("link").toString());
                    QVBoxLayout *vlay2=new QVBoxLayout();
                    QHBoxLayout *imglayout = new QHBoxLayout();
                    vlay2->setMargin(10);

                    QLabel *img = new QLabel(this);
                    img->setScaledContents(true);
                    img->setMargin(5);
                    img->setWordWrap(1);
                    img->setMaximumSize(200,200);
                    img->setMinimumSize(200,200);
                    img->setFrameShape (QFrame::Box);
                    img->setPixmap(image);

                    QLabel *title = new QLabel(query.value("title").toString());
                    title->setAlignment(Qt::AlignCenter);
                    title->setFixedSize(250,60);
                    title->setMargin(5);
                    title->setWordWrap(1);
                    title->setFrameShape (QFrame::Box);

                    QHBoxLayout *usrfunc = new QHBoxLayout();
                    QPushButton *star=new QPushButton();
                    star->setIcon(QIcon("./img/favorite.png"));
                    star->setIconSize(QSize(25,25));
                    star->setFixedSize(35,35);

                    QPushButton *cart=new QPushButton();
                    cart->setIcon(QIcon("./img/cart.png"));
                    cart->setIconSize(QSize(25,25));
                    cart->setFixedSize(35,35);


                    usrfunc->addStretch();
                    usrfunc->addWidget(cart);
                    usrfunc->addWidget(star);
                    usrfunc->addStretch();
                    imglayout->addStretch();
                    imglayout->addWidget(img);
                    imglayout->addStretch();

                    vlay2->addLayout(imglayout);
                    vlay2->addWidget(title);
                    vlay2->addLayout(usrfunc);

                    pHLayout1->addLayout(vlay2);
                }
                else
                {
                    end=true;
                    pHLayout1->addStretch();
                }
            }
            vlay1->addLayout(pHLayout1);
        }
        ui->scrollAreaWidgetContents->setLayout(vlay1);
    }
}

void user::on_mainpage_clicked()
{
    ui->scrollw->hide();
    ui->MainShow->show();
}
