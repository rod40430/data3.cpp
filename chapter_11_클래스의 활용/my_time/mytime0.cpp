// mytime0.cpp -- Time 클래스의 메서드 구현
#include <iostream>
#include "mytime0.hpp"

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

Time & Time::Sum(const Time & t)
{
  this->minutes += t.minutes;
  this->hours += t.hours + (this->minutes / 60);
  this->minutes %= 60;
  
  return *this;
}

void Time::Show() const
{
  std::cout<<hours<<"시간, "<<minutes<<"분\n";
}

Time::~Time()
{
  
}