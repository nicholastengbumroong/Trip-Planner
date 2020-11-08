#include <iostream>
#include "Trip.h"

using namespace std;

void printMenu(Trip& userTrip);

int main()
{

  string tripLocAddress;
  string tripLocCity;
  string tripLocState; 
  string tripLocCountry; 

  cout << "Enter trip street address: " << endl;
  getline(cin, tripLocAddress);
  cout << "Enter trip city: " << endl;
  getline(cin, tripLocCity);
  cout << "Enter trip state: " << endl;
  getline(cin, tripLocState);
  cout << "Enter trip country: " << endl;
  getline(cin, tripLocCountry);

  Location tripLocation(tripLocAddress, tripLocCity, tripLocState, tripLocCountry);

  int tripMonthStart;
  int tripDayStart; 
  int tripYearStart;
  int tripMonthEnd;
  int tripDayEnd; 
  int tripYearEnd;

  cout << "Enter trip start month: " << endl; 
  cin >> tripMonthStart; 
  cout << "Enter trip start day: " << endl; 
  cin >> tripDayStart; 
  cout << "Enter trip start year: " << endl;
  cin >> tripYearStart;

  cout << "Enter trip end month: " << endl; 
  cin >> tripMonthEnd; 
  cout << "Enter trip end day: " << endl; 
  cin >> tripDayEnd; 
  cout << "Enter trip end year: " << endl;
  cin >> tripYearEnd;  

  Time tripStart(tripMonthStart, tripDayStart, tripYearStart); 
  Time tripEnd(tripMonthEnd, tripDayEnd, tripYearEnd);

  Trip trip(tripLocation, tripStart, tripEnd);
  
  printMenu(trip);
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
    string eventLocCountry = "";
    string eventLocState = "";
    string eventLocCity = "";
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
      // cout << "Enter event country: " << endl; 
      // cin.ignore();
      // getline(cin, eventLocCountry);
      // cout << "Enter event state: " << endl; 
      // getline(cin, eventLocState);
      // cout << "Enter event city: " << endl; 
      // getline(cin, eventLocCity); 
      
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
      Location eventLoc(userTrip.getTripLocation().getCity(), 
                        userTrip.getTripLocation().getStateOrProvince(),
                        userTrip.getTripLocation().getCountry());

      Event newEvent(eventName, eventDesc, eventPrice, start, end, eventLoc);
      
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
