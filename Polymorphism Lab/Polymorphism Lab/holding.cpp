//  holding.cpp

#include "holding.h"


Holding::Holding(char* name, int num){
    title = new char[strlen(name) + 1];
    strcpy(title, name);
    number = num;
}

Holding::Holding(const Holding& holder){
    title = new char[strlen(holder.title + 1)];
    strcpy(title, holder.title);
    number = holder.number;
}

Holding::~Holding(){
    delete [] title;
    number = 0;
}