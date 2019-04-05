//  recording.h

#ifndef __Polymorphism_Lab__recording__
#define __Polymorphism_Lab__recording__

#include "holding.h"

class Recording: public Holding {
private:
    char* performer;
    char* format;
public:
    Recording(char*, int, char*, char);
    Recording(const Recording&);
    virtual ~Recording();
    virtual void print();
};

#endif