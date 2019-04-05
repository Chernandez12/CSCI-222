//  book.cpp

#include "book.h"
#include <fstream>

extern ofstream csis;


Book::Book(char* name, int num, char* auth) : Holding(name, num){
    author = new char[strlen(auth) + 1];
    strcpy(author, auth);
}

Book::Book(const Book& book) : Holding(book){
    author = new char[strlen(book.author + 1)];
    strcpy(author, book.author);
}

Book::~Book(){
    delete [] author;
}

void Book::print(){
    cout << "BOOK: " << author << " \"" << title << "\" " << number << endl;
    csis << "BOOK: " << author << " \"" << title << "\" " << number << endl;
}