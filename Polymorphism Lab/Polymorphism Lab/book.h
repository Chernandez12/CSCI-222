//  book.h

#ifndef __Polymorphism_Lab__book__
#define __Polymorphism_Lab__book__

#include "holding.h"

class Book: public Holding {
private:
    char* author;
public:
    Book(char*, int, char*);
    Book(const Book&);
    virtual ~Book();
    virtual void print();
};

#endif