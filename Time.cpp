#include "Time.h"

#include <string>
#include <iostream>

using namespace std;

Time :: Time()
{
    year = 0;
    day = 0;
    month = 0;
    
    hour = 0;
    minute = 0;
    ampm = '';
}

Time :: Time( int Nmonth, int Nday, int Nyear )
{
    month = Nmonth;
    day = Nday;
    year = Nyear;
    
}

Time :: Time( int Nmonth, int Nday, int Nyear, int Nhour, int Nminute, string Nampm )
{
    month = Nmonth;
    day = Nday;
    year = Nyear;
    
    hour = Nhour;
    minute = Nminute;
    ampm = Nampm;
}

Time :: Time( int Nhour , int Nminute )
{
    hour = Nhour;
    minute = Nminute;
}

void Time :: setMonth( int Nmonth )
{
    month = Nmonth;    
}

void Time :: setDay( int Nday )
{
    day = Nday;    
}

void Time :: setYear( int Nyear )
{
    year = Nyear;
}

void Time :: setHour( int Nhour )
{
    hour = Nhour;
}

void Time :: setMinute( int Nmin )
{
    minute = Nmin;
}

void Time :: setAmpm( string Nampm )
{
    ampm = Nampm;
}

int Time :: getMonth() const
{
    return month;
}

int Time :: getDay() const
{
    return day;
}

int Time :: getYear() const
{
    return year;
}

int Time :: getHour() const
{
    return hour;
}

string Time :: getAmpm() const
{
    return ampm;
}

int Time :: convertToMinutes() const
{
    int totalMin;
    
    totalMin = ( hour * 60 ) + minute;
    
    return totalMin;
}

Time Time :: operator-( Time time1 ) const
{
    Time newTime;
    int num1 = time1.convertToMinutes();
    int num2 = this->convertToMinutes();
    int hourVal; // bigger
    int minuteVal; // bigger
    
    int hourVal2; // smaller
    int minuteVal2;
    
    if ( num1 >= num2 )
    {
        hourVal = time1.hour;
        minuteVal = time1.minute;
        hourVal2 = this->hour;
        minuteVal2 = this->minute;
    }    
    
    else
    {
        hourVal = this->hour;
        minuteVal = this->minute;
        hourVal2 = time1.hour;
        minuteVal2 = time1.minute;
    }
    
    int newHour = hourVal - hourVal2;
    int newMin = minuteVal - minuteVal2;
    
    newTime( newHour, newMin );
    
    return newTime;
}
