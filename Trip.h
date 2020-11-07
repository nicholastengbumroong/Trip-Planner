#ifndef TRIP_H
#define TRIP_H

#include <vector>
#include "Time.h"
#include "Location.h"
#include "Event.h" 

class Trip {
    private:
        vector<Trip> tripList; 
        vector<Event> eventList;
        Time time; 
        Location location; 
         

    public:
        Trip(); 
        Trip(const Location&, const Time&); 
        Trip(); 

        void createInfoFile() const; 



};

#endif;
