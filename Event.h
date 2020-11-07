#ifndef __EVENT_H__
#define __EVENT_H__

#include "Location.h"
#include "Time.h"
#include <iostream>

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
        Event(const string &n, const Time &s, const Time &e);
        Event(const string &n, int p, const Time &s, const Time &e);
        Event(const string &n, const string &d, int p, const Time &s, const Time &e, const Location &l);

        string getName() const;
        string getDescription() const;
        int getPrice() const;
        Time getStartTime() const;
        Time getEndTime() const;
        Location getLocation() const;
        
        void setName(const string &name);
        void setDescription(const string &description);
        void setPrice(int price);
        void setStartTime(const Time &start);
        void setEndTime(const Time &end);
        void setLocaion(const Location &loc);
        
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

        friend ostream & operator<<(ostream &out, const Event &e);
};

#endif
