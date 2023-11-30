// studenti.hpp -- private 상속을 사용하는 Student 클래스를 정의한다
#ifndef STUDENTI_H_
#define STUDENTI_H_

#include <iostream>
#include <valarray>
#include <cstring>

class Student : std::string, std::valarray<double>  // 상속의 기본은 priavte이라 생략한다
{
private:
  typedef std::valarray<double> ArrayDb;
  // scores 출력을 위한 private 메서드
  std::ostream & arr_out(std::ostream & os) const;
public:
// 생성자 및 파괴자
  Student(void) : std::string("Null Student"), ArrayDb() {}
  explicit Student(const std::string & s)
    : std::string(s), ArrayDb() {}
  explicit Student(int n) : std::string("Null Student"), ArrayDb(n) {}
  Student(const std::string & s, int n)
    : std::string(s), ArrayDb(n) {}
  Student(const std::string & s, const ArrayDb & a)
  : std::string(s), ArrayDb(a) {}
  Student(const char * str, const double * pd, int n)
  : std::string(str), ArrayDb(pd, n) {}
  ~Student(void) {}

// 멤버 함수
  double Average(void) const;
  double & operator[](int i);
  double operator[](int i) const;
  const std::string & Name(void) const;

// 프렌드
  // 입력
  friend std::istream & operator>>(std::istream & is, Student & stu);
  friend std::istream & getliene(std::istream & is, Student & stu);
  // 출력
  friend std::ostream & operator<<(std::ostream & os, const Student & stu);
};

#endif