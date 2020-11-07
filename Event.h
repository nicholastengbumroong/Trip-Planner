#ifndef __EVENT_H__
#define __EVENT_H__

#include "Location.h"
#include "Time.h"
#include <iostream>
#include <iomanip>

using namespace std;

class Event {
    private:
        string name;
        string description;
        int price;
        Time start, end;
        Location loc;
    public:
        Event();
        Event(string &n, Time s, Time e);
        Event(string &n, int p, Time s, Time e);
        Event(string &n, string &d, int p, Time &s, Time &e, Location &l);

        string getName() const;
        string getDescription() const;
        int getPrice() const;
        Time getStartTime() const;
        Time getEndTime() const;
        Location getLocation() const;
        
        void setName(string &name);
        void setDescription(string &description);
        void setPrice(int price);
        void setStartTime(Time &start);
        void setEndTime(Time &end);
        void setLocaion(Location &loc);
        
        /*
            *****Day 1*****
            (1pm - 2pm) - Event A
                Location: 
                Expected Price:
                Description: 
            (2pm - 3pm) - Event B
                Location: 
                Expected Price: 
                Description: 

            *****Day 2*****
            (1pm - 2pm) - Event C
                Location: 
                Expected Price:
                Description: 
            (2pm - 3pm) - Event D
                Location: 
                Expected Price: 
                Description: 

        */

        friend ostream & operator<<(ostream &out, Event &e);
};

#endif
