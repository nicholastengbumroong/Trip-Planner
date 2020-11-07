#ifndef __LOCATION_H__
#define __LOCATION_H__

#include <iostream>
#include <string>
using namespace std;

class Location{
    private:
        string streetAddress;
        string city;
        string stateOrProvince;
        string country;

    public:
        Location();
        Location(const string&, const string&, const string&);
        Location(const string&, const string&, const string&, const string&);
        void displayLocation();


};

#endif
