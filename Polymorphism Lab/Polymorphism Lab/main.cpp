// Lab: Polymorphism (Library Holdings)
// Author: Carlos A. Hernandez
// Date: 12/3/17

#include <stdio.h>
#include <fstream>
#include "holding.h"
#include "book.h"
#include "recording.h"

Holding * setHolder();
using namespace std;
ofstream csis;

int main(int argc, const char * argv[]){
    Holding** holding = new Holding*[5];
    
    csis.open("csis.txt");
    
    cout << "Enter holdings to be stored in a list: " << endl << endl;
    csis << "Enter holdings to be stored in a list: " << endl << endl;
    for (int i = 0; i < 5; i++) {
        holding[i] = setHolder();
    }
    
    cout << endl;
    cout << "Here are the holdings:" << endl << endl;
    csis << endl;
    csis << "Here are the holdings:" << endl << endl;
    for (int i = 0; i < 5; i++) {
        holding[i]->print();
    }
    delete [] holding;
    csis.close();
    return 0;
}

Holding * setHolder(){
    char selection;
    char title[140];
    int callNumber = 0;
    Holding *holder;
    
    cout << "Enter B for book or R for recording: ";
    cin >> selection;
    selection = toupper(selection);
    cin.ignore();
    csis << "Enter B for book or R for recording: " << selection << endl;
    
    if (selection == 'B') {
        char author[140];
        
        cout << "Enter book title: ";
        cin.getline(title, 140);
        csis << "Enter book title: " << title << endl;
        
        cout << "Enter book author: ";
        cin.getline(author, 140);
        csis << "Enter book author: " << author << endl;
        
        cout << "Enter call number: ";
        cin >> callNumber;
        csis << "Enter call number: " << callNumber << endl;
        
        holder = new Book(title, callNumber, author);
        
        return holder;
    }
    
    if (selection == 'R') {
        char performer[140];
        char format;
        
        cout << "Enter recording title: ";
        cin.getline(title, 140);
        csis << "Enter recording title: " << title << endl;
        
        cout << "Enter performer: ";
        cin.getline(performer, 140);
        csis << "Enter performer: " << performer << endl;
        
        cout << "Enter format: (M)P3, (W)AV, (A)IFF): ";
        cin >> format;
        csis << "Enter format: (M)P3, (W)AV, (A)IFF): " << format << endl;
        
        cout << "Enter call number: ";
        cin >> callNumber;
        csis << "Enter call number: " << callNumber << endl;
        
        holder = new Recording(title, callNumber, performer, format);
        return holder;
    }
    
    return holder;
}
