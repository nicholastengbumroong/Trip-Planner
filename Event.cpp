#include "Event.h"

Event::Event() {
    name = "No Name";
    description = "";
    price = 0;
}
Event::Event(const string &n, const Time &s, const Time &e) {
    name = n;
    description = "";
    price = 0;
    start = s;
    end = e;
}
Event::Event(const string &n, int p, const Time &s, const Time &e) {
    name = n;
    description = "";
    price = p;
    start = s;
    end = e;
}
Event::Event(const string &n, const string &d, int p, const Time &s, const Time &e, const Location &l) {
    name = n;
    description = d;
    price = p;
    start = s;
    end = e;
    loc = l;
}

string Event::getName() const { return name; }
string Event::getDescription() const { return description; }
int Event::getPrice() const { return price; }
Time Event::getStartTime() const { return start; }
Time Event::getEndTime() const { return end; }
Location Event::getLocation() const { return loc; }

void Event::setName(const string &n) { name = n; }
void Event::setDescription(const string &d) { description = d; }
void Event::setPrice(int p) { price = p; }
void Event::setStartTime(const Time &s) { start = s; }
void Event::setEndTime(const Time &e) { end = e; }
void Event::setLocaion(const Location &l) { loc = l; }

//Need Time implementation to finish this
ostream & operator<<(ostream &out, const Event &ev) {
    out << "(" << ev.start << " - " << ev.end << ") - ";
    out << ev.name << endl;
    out << "\t" << "Location: " << ev.loc.getStreet() << endl;
    out << "\t" << "          " << ev.loc.getCity() << ", " << ev.loc.getStateOrProvince() << endl;
    out << "\t" << "          " << ev.loc.getCountry() << endl;
    out << "\t" << "Expected Price: $" << ev.price << endl;
    out << "\t" << "Description: " << ev.description << endl;
    return out;
}
