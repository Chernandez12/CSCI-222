//
//  String.cpp
//  Inheritence Lab
//
//  Created by Andre Hernandez on 11/15/17.
//  Copyright (c) 2017 Andre Hernandez. All rights reserved.
//

#include "String.h"
#include <fstream>

extern ofstream csis;

String::String(){
    buf = new char[1];
    buf[0] = NULL;
    length = 0;
}

String::String(const char* string){
    length = int(strlen(string));
    buf = new char[length+1];
    
    for (int i = 0; i < length; i++) {
        buf[i] = string[i];
    }
    buf[length] = NULL;
}

String::String(char c){
    buf = new char[2];
    
    buf[0] = c;
    length = 1;
    buf[length] = NULL;
}

String::String(int i){
    int temp = i;
    int count = 0;
    
    if (i < 0)
        i = 0;
    
    while (temp > 0) {
        temp /= 10;
        count++;
    }
    
    buf = new char[count + 1];
    sprintf(buf, "%d", i);
    length = count;
    buf[length] = NULL;
}

String::String(const String& string){
    length = string.length;
    buf = new char[length];
    buf = string.buf;
}

String::String(char c, int i){
//    buf = new char[i];
//    char charArray[i];
//    
//    for (int index = 0; index < i; index++) {
//        charArray[index] = c;
//    }
//    
//    charArray[i] = NULL;
//    buf = charArray;
//    length = int(strlen(buf));
// MISSING
}

String::~String(){length = 0;}

String& String::operator=(const String& s){
    if (this == &s)
        return *this;
    
    length = s.length;
    buf = s.buf;
    
    return *this;
}

String& String::operator=(const char* c){
    length = int(strlen(c));
    buf = (char*)c;
    
    return *this;
}

String operator+(const String& str1, const String& str2){
    int i, j;
    int length2 = str1.length + str2.length;
    String temp(length2);
    temp.length = length2;
    
    for (i = 0; i < str1.length; i++) {
        temp.buf[i] = str1.buf[i];
    }
    
    for (j = 0, i = str1.length; j < str2.length; j++, i++) {
        temp.buf[i] = str2.buf[j];
    }
    temp[length2] = NULL;
    
    return temp;
}

String operator+(const String& str1, const char* ch){
    int i, j;
    int length2 = str1.length + int(strlen(ch));
    String temp(length2);
    temp.length = length2;
    
    for (i = 0; i < str1.length; i++) {
        temp.buf[i] = str1.buf[i];
    }
    
    for (j = 0, i = str1.length; j < int(strlen(ch)); j++, i++) {
        temp.buf[i] = ch[j];
    }
    temp[length2] = NULL;
    
    return temp;
}

String operator+(const char* ch, const String& str1){
    int i, j;
    int length2 = str1.length + int(strlen(ch));
    String temp(length2);
    temp.length = length2;
    
    for (i = 0; i < int(strlen(ch)); i++) {
        temp.buf[i] = ch[i];
    }
    
    for (j = 0, i = int(strlen(ch)); j < str1.length; j++, i++) {
        temp.buf[i] = str1.buf[j];
    }
    
    temp[length2] = NULL;
    
    return temp;
}

String operator+(const String& str1, const char ch){
    int i;
    int length2 = str1.length + 1;
    String temp(length2);
    temp.length = length2;
    
    for (i = 0; i < str1.length; i++) {
        temp.buf[i] = str1.buf[i];
    }
    temp[length2 - 1] = ch;
    temp[length2] = NULL;
    
    return temp;
}

String operator+(const char ch, const String& str1){
    int i, j;
    int length2 = str1.length + 1;
    String temp(length2);
    temp.length = length2;
    
    temp[0] = ch;
    for (i = 0, j = 1; i < str1.length; i++, j++) {
        temp.buf[j] = str1.buf[i];
    }
    temp[length2] = NULL;
    
    return temp;
}

//String& String::operator+=(const String& str){
    // Missing
//}

String String::operator+() const{
    String temp;
    temp.buf = buf;
    temp.length = length;
    
    for (int i = 0; i < temp.length; i++) {
        temp[i] = toupper(temp[i]);
    }
    
    return temp;
}

int operator==(const String& str1, const String& str2){return str1.buf == str2.buf;}
int operator!=(const String& str1, const String& str2){return str1.buf != str2.buf;}
int operator< (const String& str1, const String& str2){return str1.buf < str2.buf;}
int operator<=(const String& str1, const String& str2){return str1.buf <= str2.buf;}
int operator> (const String& str1, const String& str2){return str1.buf > str2.buf;}
int operator>=(const String& str1, const String& str2){return str1.buf >= str2.buf;}

char& String::operator[](int i){
    static char ch;
    
    if (i < 0 || i > length) {
        cout << "Error: Out of Range" << endl;
        return ch = NULL;
    }
    else
        return buf[i];
    
}

char* operator+(const String& str, int i){return &str.buf[i];}
char* operator+(int i, const String& str){return &str.buf[i];}

String& String::operator++(){
    for (int i = 0; i < length; i++) {
        buf[i] = buf[i+1];
    }
    
    return *this;
}

String& String::operator--(){
    for (int i = length; i > 0; i--) {
        buf[i] = buf[i-1];
    }
    
    return *this;
}

String& String::operator++(int val){
    String temp(*this);
    ++(*this);
    
    return temp;
}

String& String::operator--(int val){
    String temp(*this);
    --(*this);
    
    return temp;
}

String String::substr(int start, int end){
    String s;
    
    for (int i = start, j = 0; j < end; i++, j++) {
        s.buf[j] = buf[i];
        s.length++;
    }
    return s;
}

int String::getLength(){return length;}

void String::print(){
    cout << "\"" << buf << "\"" << "  " << "Length = " << length << endl;
    csis << "\"" << buf << "\"" << "  " << "Length = " << length << endl;
}

ostream& operator<<(ostream& os, const String& str){
    for (int i = 0; i < str.length; i++) {
        os << str.buf[i];
    }
    
    return os;
}












