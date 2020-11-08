#include <iostream>
#include <string>
using namespace std;

#include "Location.h"

//default Location constructor
Location::Location(){
    streetAddress = "None";
    city = "None";
    stateOrProvince = "None";
    country = "None";
}

//if user lives in a country without a province/state
Location::Location(const string& streetAddress, const string& city, const string& country){
    this->streetAddress = streetAddress;
    this->city = city;
    this->stateOrProvince = country; //e.g "Andorra, Andorra" or "Singapore, Singapore" instead of "California, USA";
    this->country = country;
}

Location::Location(const string& streetAddress, const string& city, const string& stateOrProvince, const string& country){
    this->streetAddress = streetAddress;
    this->city = city;
    this->stateOrProvince = stateOrProvince;
    this->country = country;
}



const string Location::getStreet()const{
    return streetAddress;
}

const string Location::getCity() const{
    return city;
}

const string Location::getStateOrProvince() const{
    return stateOrProvince;
}

const string Location::getCountry() const{
    return country;
}
        
void Location::setStreet(const string& street){
    streetAddress = street;

}

void Location::setCity(const string& city){
    this->city = city;
}

void Location::setStateOrProvince(const string& stateOrProvince){
    this->stateOrProvince = stateOrProvince;
}

void Location::setCountry(const string& country){
    this->country = country;
}

ostream& operator << (ostream& out, const Location& loc){
    out << loc.getStreet() << endl;
    out << loc.getCity() << ", " << loc.getStateOrProvince() << endl;
    out << loc.getCountry() << endl;

    return out;
}
