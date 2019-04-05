//
//  game1.h
//  Poker Lab
//
//  Created by Andre Hernandez on 9/12/17.
//  Copyright (c) 2017 Andre Hernandez. All rights reserved.
//

#ifndef __Poker_Lab__game1__
#define __Poker_Lab__game1__

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <fstream>

#include "stdlib.h"
#include "time.h"

#include "card.h"
#include "deck.h"

class Game1{
    private:
    Deck deck;
    Card hand[5];
    int trials = 10;
    int hands = 10000;
    int flushNum;
    int pairNum;
    double flushRate;
    double pairRate;

    int handsNum = 0;
    
    public:
    void game1();
    int flush();
    int pair();
};

#endif /* defined(__Poker_Lab__game1__) */
