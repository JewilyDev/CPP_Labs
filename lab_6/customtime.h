#ifndef CUSTOMTIME_H
#define CUSTOMTIME_H
#include <string>
#include <iostream>

class CustomTime
{
public:
    CustomTime();
    CustomTime(int h,int m);
    CustomTime(std::string time);
    void print();
    CustomTime operator + (int time);
    int operator - (CustomTime time);
    bool operator == (CustomTime time);
private:
    int hours;
    int mins;
    static const int hoursInDay;
    static const int minsInHours;
};

#endif // CUSTOMTIME_H
