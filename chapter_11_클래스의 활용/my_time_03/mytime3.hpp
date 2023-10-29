// mytime3.hpp -- 프렌드를 사용하는 Time 클래스
#ifndef MYTIME3_H_
#define MYTIME3_H_

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

  friend Time operator*(const double m, const Time & t)
    {return t * m;}  // 인라인 정의(클래스 안에 함수를 정의하면 인라인이 된다)
  friend std::ostream & operator<<(std::ostream & os, const Time & t);

  ~Time();
};

#endif