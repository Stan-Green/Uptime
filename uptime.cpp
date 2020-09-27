// uptime.cpp
// Dipaly the uptime of the PC.
// Written by: Stan Green 8/8/2020

#include <iostream>
#include<string> 
#include <Windows.h>
#include <time.h> 

int main()
{
    ULONGLONG ll_milSec = GetTickCount64();
    long YEAR = 31536000000;
    long DAY = 86400000;
    long HOUR = 3600000;
    long MINUTE = 60000;
    long SECOND = 1000;

    std::string ls_years = "0";
    std::string ls_days = "0";
    std::string ls_hours = "0";
    std::string ls_minutes = "0";
    std::string ls_seconds = "0";
    std::string ls_milseconds = "0";


    UINT li_years = 0;
    UINT li_days = 0;
    UINT li_hours = 0;
    UINT li_minutes = 0;
    UINT li_seconds = 0;

    time_t now = time(0);
    tm localTime;
    now = time(NULL);
    localtime_s(&localTime, &now);

    std::cout << "Current Time: " << (&localTime)->tm_hour << ":" << (&localTime)->tm_min << ":" << (&localTime)->tm_sec << "\n";

    std::string ls_milSec = std::to_string(ll_milSec);
    std::cout << "Uptime in milliseconds: " << ls_milSec << "\n\n";

    li_years = ll_milSec / YEAR;
    if (li_years > 0)
    {
        ll_milSec = ll_milSec - (li_years * YEAR);
        ls_years = std::to_string(li_years);
    }

    li_days = ll_milSec / DAY;
    if (li_days > 0)
    {
        ll_milSec = ll_milSec - (li_days * DAY);
        ls_days = std::to_string(li_days);
    }

    li_hours = ll_milSec / HOUR;
    if (li_hours > 0)
    {
        ll_milSec = ll_milSec - (li_hours * HOUR);
        ls_hours = std::to_string(li_hours);
    }
 
    li_minutes = ll_milSec / MINUTE;
    if (li_minutes > 0)
    {
        ll_milSec = ll_milSec - (li_minutes * MINUTE);
        ls_minutes = std::to_string(li_minutes);
    }

    li_seconds = ll_milSec / SECOND;
    if (li_seconds > 0)
    {
        ll_milSec = ll_milSec - (li_seconds * SECOND);
        ls_seconds = std::to_string(li_seconds);
    }
    
    if (ll_milSec > 0)
    {
        ls_milseconds = std::to_string(ll_milSec);
    }

      std::cout << "*** Uptime ***\n" << "Years: " << ls_years << "\n" << "Days: " << ls_days << "\n" << "Hours: " << ls_hours << "\n" << "Minutes: " << ls_minutes << "\n" << "Seconds: " << ls_seconds << "\n" << "Milliseconds:  " << ls_milseconds << "\n";
 }
 
