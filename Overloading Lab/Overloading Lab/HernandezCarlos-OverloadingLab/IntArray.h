//  IntArray.h

#ifndef __Operator_Overloading_Lab__IntArray__
#define __Operator_Overloading_Lab__IntArray__

#include <iostream>

using namespace std;

class IntArray {
private:
    string name;
    int min;
    int max;
    int size;
    int array[];
    
public:
    IntArray();
    IntArray(int);
    IntArray(int, int);
    IntArray(const IntArray&);
    
    void setName(string);
    int low();
    int high();
    
    IntArray& operator=(IntArray&);
    int operator==(IntArray&);
    int operator!=(IntArray&);
    int& operator[](int);
    friend IntArray operator+(IntArray&, IntArray&);
    void operator+=(IntArray&);
    friend ostream& operator<<(ostream&, const IntArray&);
};


#endif