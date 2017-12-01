#ifndef FOOD_H
#define FOOD_H

#include <product.h>

class food:public product
{
public:
    food();
};

class snacks:public food
{
public:
    snacks();
};

class health:public food
{
public:
    health();
};

class fruits:public food
{
public:
    fruits();
};
#endif // FOOD_H
