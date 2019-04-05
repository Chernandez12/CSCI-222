//
//  ReverseString.h
//  Inheritence Lab
//
//  Created by Andre Hernandez on 11/9/17.
//  Copyright (c) 2017 Andre Hernandez. All rights reserved.
//

#ifndef __Inheritence_Lab__ReverseString__
#define __Inheritence_Lab__ReverseString__

#include <stdio.h>
#include <iostream>
#include "String.h"


class ReverseString: public String {
private:
    char* rstring;
public:
    ReverseString();
    ReverseString(const ReverseString&);
    ReverseString(const char*);
    ReverseString& operator=(const ReverseString&);
    ReverseString operator~();
};

#endif /* defined(__Inheritence_Lab__ReverseString__) */
