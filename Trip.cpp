#include <iostream>
#include <fstream> 
#include "Trip.h" 

using namespace std; 

Trip::Trip() {
    location = Location(); 
    time = Time(); 
    duration = Time();
}

Trip::Trip(const Location& loc, const Time& t) {
    location = loc; 
    time = t;  
}

Trip::Trip(const Location& loc, const Time& t, const Time& d){
    location = loc; 
    time = t; 
    duration = d; 
}

void Trip::addEvent(const Event& newEvent) {
    eventList.push_back(newEvent); 
}

void Trip::removeEvent(const string& eventName) {
    for (unsigned i = 0; i < eventList.size(); i++) {
        if (eventName == eventList.at(i).getName()) {
            eventList.erase(eventList.begin() + i);
        }
    }
}

void Trip::createInfoFile() const {
    ofstream infoFile("InfoFile.txt");
    infoFile << location << endl; 
    infoFile << time.getMonth() << "/" << time.getDay() << "/" << time.getYear() << endl;
    for (Event event : eventList){
        infoFile << event; 
    } 
    
}

void Trip::createItinerary() const {
    ofstream it("Itinerary.txt");
    it << "------ITINERARY------" << endl; 
    for (Event event : eventList){
        it << event; 
    } 
}