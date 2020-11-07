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
        const string getStreet() const; 
        const string getCity() const;
        const string getStateOrProvince() const;
        const string getCountry() const;
        void setStreet(const string&);
        void setCity(const string&);
        void setStateOrProvince(const string&);
        void setCountry(const string&);
        friend ostream& operator << (ostream& out, const Location& loc);


};

#endif
