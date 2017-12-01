#include "product.h"

product::product()
{

}

string product::getCity()
{
    return city;
}

double product::getDiscount()
{
    return discount;
}

string product::getInfo()
{
    return info;
}

int product::getNum()
{
    return num;
}

double product::getPrice()
{
    return price;
}

string product::getType()
{
    return type;
}

double product::getFull()
{
    return full;
}

double product::getCut()
{
    return cut;
}

string product::getlink()
{
    return link;
}

void product::setType(string s)
{
    type=s;
}

void product::setPrice(double d)
{
    price=d;
}

void product::setCity(string s)
{
    city=s;
}

void product::setNum(int n)
{
    num=n;
}
void product::setInfo(string s)
{
    info=s;
}

void product::setDiscount(double d)
{
    discount=d;
}

void product::setFull(double d)
{
    full=d;
}

void product::setCut(double d)
{
    cut=d;
}

void product::setlink(string s)
{
    link=s;
}

void product::settitle(string s)
{
    title=s;
}

string product::gettitle()
{
    return title;
}

void product::setid(string s)
{
    id=s;
}

string product::getid()
{
    return id;
}
