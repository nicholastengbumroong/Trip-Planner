#include "Time.h"

using namespace std;

Time :: Time()
{
    year = 0;
    day = 0;
    month = 0;
    
    hour = 0;
    minute = 0;
}

Time :: Time( int Nmonth, int Nday, int Nyear )
{
    month = Nmonth;
    day = Nday;
    year = Nyear;
    
}

Time :: Time( int Nmonth, int Nday, int Nyear, int Nhour, int Nminute )
{
    month = Nmonth;
    day = Nday;
    year = Nyear;
    
    hour = Nhour;
    minute = Nminute;
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

int Time :: getMinute() const
{
    return minute;
}

int Time :: convertToMinutes() const
{
    int totalMin;
    
    totalMin = ( hour * 60 ) + minute;
    
    return totalMin;
}

Time Time :: operator-( Time time1 ) const
{
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
    
    if ( newHour > 12 )
    {
        newHour = newHour - 12;
    }
    
    Time newTime( newHour, newMin );
    
    return newTime;
}

ostream& operator<< (ostream& out, Time t1)
{
    out << t1.hour;
    out << ":";
    if ( t1.minute > 9 )
    {
        out << t1.minute;
    }
    
    else
    {
        out << "0" << t1.minute;
    }
    return out;
}
