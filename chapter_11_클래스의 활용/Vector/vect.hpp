// vect.hpp -- 모든 상태와 <<를 사용하는, Vector 클래스
#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>

namespace VECTOR
{
  class Vector
  {
  public:
    enum Mode {RECT, POL};
    // 직사각형을 위해서는 RECT를, Polar modes를 위해서는 POL을 사용한다
  private:
    double x;  // 수평 선분
    double y;  // 수직 선분
    double mag;  // 백터의 길이
    double ang;  // 바위 (도)로 표시되는 백터의 방향
    Mode mode;  // POL을 위해서 RECT를 (RECT or POL)
    // 값들을 설정하는 private 메서드들
    void set_mag();
    void set_ang();
    void set_x();
    void set_y();
  public:
    Vector();
    Vector(double n1, double n2, Mode form = RECT);

    void reset(double n1, double n2, Mode form = RECT);
    double xval() const {return x;}  // x값 보고
    double yval() const {return y;}  // y값 보고
    double magval() const {return mag;}  // 크기를 보고한다
    double angval() const {return ang;}  // 각도를 보고한다
    void polar_mode();  // 모드를 'P'로 설정한다
    void rect_mode();  // 모드를 'R'로 설정한다

    // 연산자 오버로딩
    Vector operator+(const Vector & b) const;
    Vector operator-(const Vector & b) const;
    Vector operator-() const;
    Vector operator*(const double n) const;

    // 프렌드 함수
  friend Vector operator*(double n, const Vector & a);
  friend std::ostream &
    operator<<(std::ostream & os, const Vector & v);

    ~Vector();
  };
}  // namespace VECTOR의 끝

#endif