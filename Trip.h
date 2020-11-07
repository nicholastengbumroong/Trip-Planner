#ifndef TRIP_H
#define TRIP_H

#include <vector>
#include "Time.h"
#include "Location.h"
#include "Event.h" 

class Trip {
    private:
        vector<Event> eventList;
        Time time; 
        Location location; 
         

    public:
        Trip(); 
        Trip(const Location&, const Time&); 

        void addEvent() const; 
        void removeEvent(const string& eventName); 
        void createInfoFile() const; 



};

#endif;
