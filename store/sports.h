#ifndef SPORTS_H
#define SPORTS_H

#include <product.h>

class sports: public product
{
public:
    sports();
};

class Equipment: public sports
{
public:
    Equipment();
};

class SportClothes: public sports
{
public:
    SportClothes();
};

class SportShoes: public sports
{
public:
    SportShoes();
};
#endif // SPORTS_H
