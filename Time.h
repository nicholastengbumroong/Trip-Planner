#ifndef TIME_H
#define TIME_H

#include <string>
#include <iostream>

using namespace std;

class Time {
    public:
        Time();
        Time( int Nmonth, int Nday, int Nyear );
        Time( int Nmonth, int Nday, int Nyear, int Nhour, int Nminute );
        Time( int Nhour, int Nminute );
    
        void setMonth( int );
        void setDay( int );
        void setYear( int );
        void setHour( int );
        void setMinute( int );
    
        int getMonth() const;
        int getDay() const;
        int getYear() const;
        int getHour() const;
        int getMinute() const;
    
        int convertToMinutes() const;    
    
        Time operator-( Time ) const;
    
    private:
        unsigned int year;
        unsigned int month;
        unsigned int day;
        
        unsigned int hour;
        unsigned int minute; 
};

#endif
