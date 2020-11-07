#ifndef TRIP_H
#define TRIP_H

#include <vector>
#include "Time.h"
#include "Location.h"
#include "Event.h" 

using namespace std; 

class Trip {
    private:
        vector<Event> eventList;
        Location location; 
        Time time; 
        Time duration; 

    public:
        Trip(); 
        Trip(const Location&, const Time&); 

        void addEvent(const Event&) const; 
        void removeEvent(const string& eventName); 
        void createInfoFile() const; 

};

#endif;
