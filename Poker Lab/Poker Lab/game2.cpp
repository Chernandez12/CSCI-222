//
//  game2.cpp
//  
//
//  Created by Andre Hernandez on 9/20/17.
//
//

//#include "game2.h"
#include "hand.h"
using namespace std;
ofstream csis;

int main(int argc, const char * argv[]) {
    Hand poker;
    csis.open("csis.txt");
    poker.hand();
    csis.close();
    return 0;
}