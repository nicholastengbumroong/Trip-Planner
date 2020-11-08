#include <iostream>
#include <fstream> 
#include "Trip.h" 

using namespace std; 

Trip::Trip() {
    location = Location(); 
    timeStart = Time(); 
    timeEnd = Time();
}

Trip::Trip(const Location& loc, const Time& start) {
    location = loc; 
    timeStart = start;
    timeEnd = Time();   
}

Trip::Trip(const Location& loc, const Time& start, const Time& end){
    location = loc; 
    timeStart = start; 
    timeEnd = end; 
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
    infoFile << timeStart.getMonth() << "/" << timeStart.getDay() << "/" << timeStart.getYear() << " - ";
    infoFile << timeEnd.getMonth() << "/" << timeEnd.getDay() << "/" << timeEnd.getYear() << endl;

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

Location Trip::getTripLocation() const {
    return location;
} 