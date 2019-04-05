//
//  hand.cpp
//  
//
//  Created by Andre Hernandez on 9/20/17.
//
//

#include "hand.h"

using namespace std;
extern ofstream csis;

void Hand::hand(){
    srand((unsigned)time(NULL));
    
    for (int j = 0; j < trials; j++) {
        handsNum = 0;
        flushNum = 0;
        pairNum = 0;
        for (int k = 0; k < hands; k++) {
            deck.shuffle(100);
            
            for (int i = 0; i < 5; i++){
                handDeck[i] = deck.getCard();
            }
            
            if (flush() == 1)
                flushNum++;
            
            if (pair() == 1)
                pairNum++;
            
            for (int i = 0; i < 5; i++){
                deck.addCard(handDeck[i]);
            }
            
            handsNum++;
        }
        
        flushRate = (double (flushNum) / double (handsNum)) * 100;
        pairRate = (double (pairNum) / double (handsNum)) * 100;
        
        cout.precision(2);
        cout << "Trial Number: " << j +1 << endl;
        cout << "Number of hands dealt: " << setw(13) << handsNum << endl;
        cout << "Number of flushes: " << setw(14) << flushNum << endl;
        cout << "Number of pairs: " << setw(18) << pairNum << endl;
        cout << "Percent of hands with flushes: " << "%" << flushRate << endl;
        cout << "Percent of hands with pairs: " << setw(3) << "%" << pairRate << "\n" << endl;
        csis.precision(2);
        csis << "Trial Number: " << j +1 << endl;
        csis << "Number of hands dealt: " << setw(13) << handsNum << endl;
        csis << "Number of flushes: " << setw(14) << flushNum << endl;
        csis << "Number of pairs: " << setw(18) << pairNum << endl;
        csis << "Percent of hands with flushes: " << "%" << flushRate << endl;
        csis << "Percent of hands with pairs: " << setw(3) << "%" << pairRate << "\n" << endl;
    }
}

int Hand::flush(){
    int flushBool = 1;
    
    for (int i = 1; i < 5; i++) {
        if (handDeck[i].getSuit() != handDeck[0].getSuit()) {
            flushBool = 0;
            return flushBool;
        }
    }
    return flushBool;
}

int Hand::pair(){
    int pairBool = 0;
    for (int k = 0; k < 5; k++) {
        for (int i = k+1; i < 5; i++){
            if (handDeck[k].getValue() == handDeck[i].getValue()) {
                pairBool++;
                return pairBool;
            }
        }
    }
    return pairBool;
}