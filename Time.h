#ifndef TIME_H
#define TIME_H

#include <string>
#include <iostream>

using namespace std;

Time {
    public:
        Time();
        Time( int Nmonth, int Nday, int Nyear );
        Time( int Nmonth, int Nday, int Nyear, int Nhour, int Nminute, string Nampm );
        Time( int Nhour, int Nminute );
    
        void setMonth( int );
        void setDay( int );
        void setYear( int );
        void setHour( int );
        void setMinute( int );
        void setAmpm( string );
    
        int getMonth() const;
        int getDay() const;
        int getYear() const;
        int getHour() const;
        string getAmpm() const;
    
        int convertToMinutes() const;    
    
        operator-( Time ) const;
    
    private:
        unsigned int year;
        unsigned int month;
        unisgned int day;
        
        unsigned int hour;
        unsigned int minute;
        string ampm;
    
    
    
    
     
};

#endif
