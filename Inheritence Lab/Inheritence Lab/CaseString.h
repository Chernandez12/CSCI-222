//
//  CaseString.h
//  
//
//  Created by Andre Hernandez on 11/9/17.
//
//

#ifndef ____CaseString__
#define ____CaseString__

#include <stdio.h>
#include <iostream>
#include "String.h"

class CaseString: public String {
private:
    char* upper;
    char* lower;
public:
    CaseString();
    CaseString(const CaseString&);
    CaseString(const char*);
    //CaseString& operator=(const CaseString&);
    void print();
    ~CaseString();
};

#endif /* defined(____CaseString__) */
