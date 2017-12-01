#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

class product
{
public:
    product();
    virtual string getType();
    virtual double getPrice();
    virtual string getCity();
    virtual int getNum();
    virtual string getInfo();
    virtual double getDiscount();
    virtual double getFull();
    virtual double getCut();
    virtual string getlink();
    virtual string gettitle();
    virtual string getid();

    virtual void setType(string s);
    virtual void setPrice(double d);
    virtual void setCity(string s);
    virtual void setNum(int n);
    virtual void setInfo(string s);
    virtual void setDiscount(double d);
    virtual void setFull(double d);
    virtual void setCut(double d);
    virtual void setlink(string s);
    virtual void settitle(string s);
    virtual void setid(string s);

private:
    string type;//产品种类
    string title;//标题
    double price;//原价
    string city;//发货城市
    int num;//库存
    string info;//介绍
    double discount;//折扣系数
    double full;//满减条件
    double cut;//满减金钱
    string link;//图片保存地址
    string id;//商品id
};

#endif // PRODUCT_H
