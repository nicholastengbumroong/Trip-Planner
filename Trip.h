#ifndef TRIP_H
#define TRIP_H

#include <vector>
#include <string> 
#include "Time.h"
#include "Location.h"
#include "Event.h" 

using namespace std; 

class Trip {
    private:
        
        Location location; 
        Time time; 
        Time duration; 

    public:
        vector<Event> eventList;
        Trip(); 
        Trip(const Location&, const Time& time);
        Trip(const Location&, const Time& time, const Time& duration);

        void addEvent(const Event&); 
        void removeEvent(const string& eventName); 
        void createInfoFile() const; 
        void createItinerary() const; 

};

#endif
