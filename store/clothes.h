#ifndef CLOTHES_H
#define CLOTHES_H

#include <product.h>

class clothes: public product
{
public:
    clothes();
};

class MaleClothes : public product
{
public:
    MaleClothes();
};

class FemaleClothes: public product
{
public:
    FemaleClothes();
};

class Shoes : public product
{
public:
    Shoes ();
};

#endif // CLOTHES_H
