#include <iostream>
#include "Trip.h" 

using namespace std; 

Trip::Trip() {
    location = Location(); 
    time = Time(); 
    eventList; 
}

Trip::Trip(const Location& loc, const Time& t) {
    location = loc; 
    time = t;
    eventList;  
}


void addEvent(const Event& newEvent) {
    // eventList.push_back(newEvent); 
}

void removeEvent(const string& eventName) {

}

void createInfoFile() {

}