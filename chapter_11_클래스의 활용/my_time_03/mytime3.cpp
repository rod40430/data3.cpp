// mytime3.cpp -- Time 클래스의 메서드 구현
#include <iostream>
#include "mytime3.hpp"

Time::Time()
{
  hours = minutes = 0;
}

Time::Time(int h, int m) : hours(h), minutes(m) {};

void Time::AddMin(int m)
{
  minutes += m;
  hours += minutes / 60;
  minutes %= 60;
}

void Time::AddHr(int h)
{
  hours += h;
}

void Time::Reset(int h, int m)
{
  hours = h;
  minutes = m;
}

void Time::Show() const
{
  std::cout<<hours<<"시간, "<<minutes<<"분\n";
}

Time Time::operator+(const Time & t) const
{
  Time Sum;
  Sum.minutes = this->minutes + t.minutes;
  Sum.hours = this->hours + t.hours + (Sum.minutes / 60);
  Sum.minutes %= 60;

  return Sum;
}

Time Time::operator-(const Time & t) const
{
  Time diff;
  int tot1, tot2;
  tot1 = this->hours * 60 + this->minutes;
  tot2 = t.hours * 60 + t.minutes;
  diff.minutes = (tot1 - tot2) % 60;
  diff.hours = (tot1 -tot2) / 60;

  return diff;
}

Time Time::operator*(const double mult) const
{
  Time result;
  long m = ((this->hours * 60) + this->minutes) * mult;
  result.hours = m / 60;
  result.minutes = m % 60;
    
  return result;
}

std::ostream & operator<<(std::ostream & os, const Time & t)
{
  os<<t.hours<<"시간, "<<t.minutes<<"분";
  return os;
}

Time::~Time()
{
  
}