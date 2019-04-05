//  recording.cpp

#include "recording.h"
#include <fstream>

extern ofstream csis;

Recording::Recording(char* name, int num, char* artist, char form) : Holding(name, num){
    performer = new char[strlen(artist) + 1];
    strcpy(performer, artist);
    
    if (form == 'M') {
        format = new char[4];
        format = (char*)"MP3";

    }
    if (form == 'W') {
        format = new char[4];
        format = (char*)"WAV";
        
    }
    if (form == 'A') {
        format = new char[4];
        format = (char*)"AIFF";
        
    }
    else {
        cout << "Error: Invalid Option" << endl;
    }
}

Recording::Recording(const Recording& record) : Holding(record){
    performer = new char[strlen(record.performer + 1)];
    format = new char[strlen(record.format + 1)];
    strcpy(performer, record.performer);
    strcpy(format, record.format);
}

Recording::~Recording(){
    delete [] performer;
    delete [] format;
}

void Recording::print(){
    cout << "RECORDING: \"" << title << "\" " << performer << " (" << format << ") " << number << endl;
    csis << "RECORDING: \"" << title << "\" " << performer << " (" << format << ") " << number << endl;
}
