// mytime1.hpp -- Time 클래스 (연산자 오버로딩 이후)
#ifndef MYTIME1_H_
#define MYTIME1_H_

class Time
{
private:
  int hours;
  int minutes;
public:
  Time();
  Time(int h, int m = 0);
  void AddMin(int m);
  void AddHr(int h);
  void Reset(int h = 0, int m = 0);
  Time & operator+(const Time & t);
  void Show() const;

  ~Time();
};

#endif