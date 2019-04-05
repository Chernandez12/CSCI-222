//  IntArray.cpp

#include "IntArray.h"
#include <fstream>

extern ofstream csis;

IntArray::IntArray() {
    min = 0;
    max = 9;
    size = 10;
    array[size];
}

IntArray::IntArray(int upper) {
    min = 0;
    max = upper - 1;
    size = upper;
    array[size];
}

IntArray::IntArray(int lower, int upper) {
    if (lower > upper) {
        cout << "Error: Out of Bounds. Program Halt..." << endl;
        csis << "Error: Out of Bounds. Program Halt..." << endl;
    }
    
    else {
        min = lower;
        max = upper;
        size = ((upper) - (lower)) + 1;
        array[size];
    }
}

IntArray::IntArray(const IntArray& a) {
    min = a.min;
    max = a.max;
    size = a.size;
    
    for (int i = a.min; i <= a.max; i++) {
        array[i] = a.array[i];
    }
}

void IntArray::setName(string s) {name = s;}
int IntArray::low() {return min;}
int IntArray::high() {return max;}

IntArray& IntArray::operator= (IntArray& a) {
    min = a.min;
    max = a.max;
    int offset = a.min;
    int* ptr = (a.array+offset);
    
    if (size != a.size) {
        cout << "Error: Size Mismatch. Program Halt..." << endl << endl;
        csis << "Error: Size Mismatch. Program Halt..." << endl << endl;
    }
    
    for (int i = min; i <= max; i++) {
        array[i] = *(ptr+i);
    }
    return *this;
}

int IntArray::operator== (IntArray& a) {
    int offset = a.min;
    int* ptr1 = (array+min);
    int* ptr2 = (a.array+offset);
    int check = 0;
    
    if ((size) == (a.size)) {
        for (int i = min; i <= max; i++) {
            if (*(ptr1+i) == *(ptr2+i))
                check = 1;
            else
                return 0;
        }
    }
    return check;
}

int IntArray::operator!= (IntArray& a) {
    int offset = a.min;
    int* ptr1 = (array+min);
    int* ptr2 = (a.array+offset);
    int check = 1;
    
    if ((size) == (a.size)) {
        for (int i = min; i <= max; i++) {
            if ( *(ptr1+i) == *(ptr2+i) )
                check = 0;
            else
                return 1;
        }
    }
    return check;
}

int& IntArray::operator[] (int value) {
    if (value < min || value > max) {
        cout << "Error: Out of Legal Range. Program Halt..." << endl;
        csis << "Error: Out of Legal Range. Program Halt..." << endl << endl;
    }
    return value;
}

IntArray operator+ (IntArray& a1, IntArray& a2) {
    IntArray temp(a1.size);
    int offset = a1.min;
    int offset2 = a2.min;
    int* ptr1 = (a1.array + offset);
    int* ptr2 = (a2.array + offset2);
    
    if ((a1.size) != (a2.size)) {
        cout << "Error: Must Have Same Number of Elements. Program Halt..." << endl;
        csis << "Error: Must Have Same Number of Elements. Program Halt..." << endl;
    }
    else {
        for (int i = 0; i <= temp.size; i++) {
            temp.array[i] = *(ptr1+i) + *(ptr2+i);
        }
    }
    return IntArray(temp);
}

void IntArray::operator+= (IntArray& a) {
    int offset = a.min;
    int* ptr = (a.array + offset);
    
    if ( (max - min) != (a.max - a.min) ) {
        cout << "Error: Must Have Same Number of Elements. Program Halt..." << endl;
        csis << "Error: Must Have Same Number of Elements. Program Halt..." << endl;
    }
    else {
        for (int i = min; i <= max; i++) {
            array[i] = *(array+i) + *(ptr+i);
        }
    }
}

ostream& operator<<(ostream& os, const IntArray& a) {
    if (a.min == a.max) {
        int i = a.min;
        os << a.name << "[" << i << "] = " << a.array[i] << endl;
    }
    else {
        for (int i = a.min; i <= a.max; i++) {
            os << a.name << "[" << i << "] = " << a.array[i] << endl;
        }
    }
    return os;
}
