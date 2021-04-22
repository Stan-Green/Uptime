// uptime.cpp
// Dipaly the uptime of the PC.
// Written by: Stan Green 8/8/2020

//Same bacsic concept as uptime on Linux.

// 4/20/2021 - Removed Year as it was wrong, due to leap year, and Winodows computers don't stay up for over a year. If it does it will just have days >365 (or 366)

#include <iostream>
#include<string> 
#include <Windows.h>
#include <time.h> 

int main()
{
    ULONGLONG ll_milSec = GetTickCount64();
    LONG DAY = 86400000;
    LONG HOUR = 3600000;
    LONG MINUTE = 60000;
    LONG SECOND = 1000;

       std::string ls_days = "0";
    std::string ls_hours = "0";
    std::string ls_minutes = "0";
    std::string ls_seconds = "0";
    std::string ls_milseconds = "0";


    LONG ll_days = 0;
    LONG ll_hours = 0;
    LONG ll_minutes = 0;
    LONG ll_seconds = 0;

    time_t now = time(0);
    tm localTime;
    now = time(NULL);
    localtime_s(&localTime, &now);

    std::cout << "Current Time: " << (&localTime)->tm_hour << ":" << (&localTime)->tm_min << ":" << (&localTime)->tm_sec << "\n";

    std::string ls_milSec = std::to_string(ll_milSec);
    std::cout << "Uptime in milliseconds: " << ls_milSec << "\n\n";

    ll_days = ll_milSec / DAY;
    if (ll_days > 0)
    {
        ll_milSec = ll_milSec - (ll_days * DAY);
        ls_days = std::to_string(ll_days);
    }

    ll_hours = ll_milSec / HOUR;
    if (ll_hours > 0)
    {
        ll_milSec = ll_milSec - (ll_hours * HOUR);
        ls_hours = std::to_string(ll_hours);
    }
 
    ll_minutes = ll_milSec / MINUTE;
    if (ll_minutes > 0)
    {
        ll_milSec = ll_milSec - (ll_minutes * MINUTE);
        ls_minutes = std::to_string(ll_minutes);
    }

    ll_seconds = ll_milSec / SECOND;
    if (ll_seconds > 0)
    {
        ll_milSec = ll_milSec - (ll_seconds * SECOND);
        ls_seconds = std::to_string(ll_seconds);
    }
    
    if (ll_milSec > 0)
    {
        ls_milseconds = std::to_string(ll_milSec);
    }

       std::cout << "*** Uptime ***\n" << "Days: " << ls_days << "\n" << "Hours: " << ls_hours << "\n" << "Minutes: " << ls_minutes << "\n" << "Seconds: " << ls_seconds << "\n" << "Milliseconds:  " << ls_milseconds << "\n";
 }
 
