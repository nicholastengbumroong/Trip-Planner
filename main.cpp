#include <iostream>
#include "Trip.h"

using namespace std;

void printMenu(Trip& userTrip);

int main()
{
  // Time start1(1, 30);
  // Time end1(6, 40);
  // Event event1("supercool event", start1, end1);
  // event1.setDescription("This event is super cool");

  // Location loc;
  // loc.setCountry("United States");
  // loc.setStateOrProvince("Nevada");
  // loc.setCity("City of Nevada");
  // loc.setStreet("1232 Nevada Street");

  // Time tripTime(2, 23, 2012);
  // Trip trip(loc, tripTime);

  // trip.addEvent(event1);

  // trip.createInfoFile();
  // trip.createItinerary();

  Trip trip;
  
  printMenu(trip);
  // for (Event event : trip.eventList) {
  //   cout << event.getName(); 
  // }
  return 0;
}

void printMenu(Trip &userTrip)
{
  char userInp = ' ';
  bool loop = false;
  while (userInp != 'q')
  {

    if (loop == false)
    {
      cout << "MENU" << endl;
      cout << "a - Add an event" << endl;
      cout << "d - Remove an event" << endl;
      cout << "c - Create information and itinerary" << endl;
      cout << "q - Quit" << endl;
      cout << endl;
      cout << "Choose an option: ";
      cin >> userInp;
      cout << endl;
    }
    else
    {
      cout << "Choose an option: ";
      cin >> userInp;
      cout << endl;
    }

    string eventName = "";
    string eventDesc = "";
    int startTimeHour;
    int startTimeMinute;
    int endTimeHour;
    int endTimeMinute;
    int eventPrice = 0;

    Time start;
    Time end;

    switch (userInp)
    {
    case 'a':
    {
      cout << endl;
      cout << "ADD EVENT" << endl;
      cin.ignore();
      cout << "Enter the event name: " << endl;
      getline(cin, eventName);
      cout << "Enter the event description: " << endl;
      getline(cin, eventDesc);
      cout << "Enter the event price: " << endl;
      cin >> eventPrice;
      
      char know;
      cout << "Do you know the start and end time (y/n): ";
      cin >> know;
      cout << endl;
      cin.ignore();
      if (know == 'y')
      {
        cout << "Enter the start time hour: " << endl;
        cin >> startTimeHour;
        cout << "Enter the start time minute: " << endl;
        cin >> startTimeMinute;
        cout << "Enter the end time hour: " << endl;
        cin >> endTimeHour;
        cout << "Enter the end time minute: " << endl;
        cin >> endTimeMinute;
        cout << endl;

        start.setHour(startTimeHour);
        start.setMinute(startTimeMinute);
        end.setHour(endTimeHour);
        end.setMinute(endTimeMinute);
      }

      else
      {
        start.setHour(0);
        start.setMinute(0);
        end.setHour(23);
        end.setMinute(59);
      }
      Event newEvent(eventName, eventPrice, start, end);
      userTrip.addEvent(newEvent);
      loop = false;
      break;
    }
    case 'd':
      cout << "REMOVE EVENT" << endl;
      cin.ignore();
      cout << "Enter name of event remove: " << endl;
      getline(cin, eventName);
      userTrip.removeEvent(eventName);
      cout << endl;
      loop = false;
      break;
    case 'c':
      cout << "CREATE INFO FILE AND ITINERARY" << endl; 
      userTrip.createInfoFile();
      userTrip.createItinerary();
      break;
    case 'q':
      exit(0);
      break;
    default:
      loop = true;
      break;
    }
  }
}
