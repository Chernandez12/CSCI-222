//
//  hand.h
//  
//
//  Created by Andre Hernandez on 9/20/17.
//
//

#ifndef ____hand__
#define ____hand__

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <fstream>


#include "stdlib.h"
#include "time.h"

#include "card.h"
#include "deck.h"

class Hand{
private:
    Deck deck;
    Card handDeck[5];
    int trials = 10;
    int hands = 10000;
    int flushNum;
    int pairNum;
    double flushRate;
    double pairRate;
    
    int handsNum = 0;
    
public:
    void hand();
    int flush();
    int pair();
};

#endif /* defined(____hand__) */
