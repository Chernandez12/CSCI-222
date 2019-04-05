//  holding.h

#ifndef __Polymorphism_Lab__holding__
#define __Polymorphism_Lab__holding__

#include <iostream>

using namespace std;

class Holding {
protected:
    char* title;
    int number;
public:
    Holding(char*, int);
    Holding(const Holding&);
    virtual ~Holding();
    virtual void print() = 0;
};

#endif