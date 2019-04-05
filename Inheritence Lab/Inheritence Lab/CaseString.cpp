//
//  CaseString.cpp
//  
//
//  Created by Andre Hernandez on 11/9/17.
//
//

#include "CaseString.h"
#include <fstream>

extern ofstream csis;


CaseString::CaseString() : String() {}
CaseString::CaseString(const CaseString& cs) : String(cs){}
CaseString::CaseString(const char* ch) : String(ch) {}

//CaseString& CaseString::operator=(const CaseString& cs){}

void CaseString::print(){
    cout << lower << "  " << upper << endl;
    csis << lower << "  " << upper << endl;
}

CaseString::~CaseString(){}