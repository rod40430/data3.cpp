// mytime2.hpp -- Time 클래스 (연산자 오버로딩 이후)
#ifndef MYTIME2_H_
#define MYTIME2_H_

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
  void Show() const;

  Time operator+(const Time & t) const;
  Time operator-(const Time & t) const;
  Time operator*(const double mult) const;
  ~Time();
};

#endif