#ifndef BOOK_H
#define BOOK_H

#include <product.h>


class book: public product
{
public:
    book();
};

class novel: public book
{
public:
    novel();
};

class edu: public book
{
public:
    edu();
};

class tool: public book
{
public:
    tool();
};

#endif // BOOK_H
