//
//  String.h
//  Inheritence Lab
//
//  Created by Andre Hernandez on 11/15/17.
//  Copyright (c) 2017 Andre Hernandez. All rights reserved.
//

#ifndef __Inheritence_Lab__String__
#define __Inheritence_Lab__String__

#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

class String {
private:
    char* buf;
    int length;
public:
    String();
    String(const char*);
    String(char);
    String(int);
    String(const String&);
    String(char, int);
    // Destructor
    ~String();
    // Assigning One String Instance to Another String Instance
    String& operator=(const String&);
    // Implicit Type Conversion
    String& operator=(const char*);
    // String Concatenation
    friend String operator+(const String&, const String&);
    friend String operator+(const String&, const char*);
    friend String operator+(const char*, const String&);
    friend String operator+(const String&, const char);
    friend String operator+(const char, const String&);
    String& operator+=(const String&);
    // Overloading An Operator As Both Unary and Binary
    String operator+() const;
    // Comparing Two String Instances
    friend int operator==(const String&, const String&);
    friend int operator!=(const String&, const String&);
    friend int operator< (const String&, const String&);
    friend int operator<=(const String&, const String&);
    friend int operator> (const String&, const String&);
    friend int operator>=(const String&, const String&);
    // Overloading operator []()
    char& operator[] (int);
    friend char* operator+(const String&, int);
    friend char* operator+(int, const String&);
    // Overloading the Increment and Decrement Operators
    String& operator++();       // Prefix Form
    String& operator--();       // Prefix Form
    String& operator++(int);    // Postfix Form
    String& operator--(int);    // Postfix Form
    // Return String Length
    int getLength();
    // Substring Function
    String substr(int, int);
    // Output Function
    void print();
    friend ostream& operator<<(ostream&, const String&);
};




#endif /* defined(__Inheritence_Lab__String__) */
