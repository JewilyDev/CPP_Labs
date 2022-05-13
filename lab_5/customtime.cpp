#include "customtime.h"
const int CustomTime::hoursInDay = 24;
const int CustomTime::minsInHours = 60;
CustomTime::CustomTime()
    :hours(0),mins(0)
{

}
CustomTime::CustomTime(int h, int m)
{
  if(m >= minsInHours)
  {
   int tempDays = m / minsInHours;
   h += tempDays;
   m -= tempDays * minsInHours;
  }
  this->hours = h < hoursInDay ? h : h - hoursInDay * (h / hoursInDay);
  this->mins = m;
}
CustomTime::CustomTime(std::string time)
{
  int h = std::stoi(time.substr(0,2));
  int m = std::stoi(time.substr(3));
  if(m >= minsInHours)
  {
   int tempDays = m / minsInHours;
   h += tempDays;
   m -= tempDays * minsInHours;
  }
  this->hours = h < hoursInDay ? h : h - hoursInDay * (h / hoursInDay);
  this->mins = m;
}
void CustomTime::print()
{
  std::string h = "";
  std::string m = "";
  if(this->hours < 10)
      h += "0";
  if(this->mins < 10)
      m += "0";
  h += std::to_string(this->hours);
  m += std::to_string(this->mins);
  std::cout <<  h << ":" << m;
}

CustomTime CustomTime::operator +(int time)
{
 return CustomTime(this->hours,time + this->mins);
}

int CustomTime::operator -(CustomTime time)
{
  int h = this->hours - time.hours > 0 ? this->hours - time.hours : hoursInDay + this->hours - time.hours;
  return (h * minsInHours + (this->mins - time.mins));
}

bool CustomTime::operator ==(CustomTime time)
{
  return this->hours == time.hours && this->mins == time.mins;
}
