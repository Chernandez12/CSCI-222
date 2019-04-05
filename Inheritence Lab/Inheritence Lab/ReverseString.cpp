//
//  ReverseString.cpp
//  Inheritence Lab
//
//  Created by Andre Hernandez on 11/9/17.
//  Copyright (c) 2017 Andre Hernandez. All rights reserved.
//

#include <algorithm>
#include "ReverseString.h"

ReverseString::ReverseString() : String() {}
ReverseString::ReverseString(const ReverseString& rs) : String(rs) {}
ReverseString::ReverseString(const char* ch) : String(ch) {}

ReverseString& ReverseString::operator=(const ReverseString& rs){
    if (&rs != this)
        String::operator=(rs);
    
    return *this;
}

ReverseString ReverseString::operator~(){
    // MISSING
    
    return "\0";
}