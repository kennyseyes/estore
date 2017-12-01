#ifndef ELECTRONICS_H
#define ELECTRONICS_H

#include <product.h>

class electronics: public product
{
public:
    electronics();
};

class pc: public electronics
{
public:
    pc();
};

class camera: public electronics
{
public:
    camera();
};

class elec: public electronics
{
public:
    elec();
};
#endif // ELECTRONICS_H
