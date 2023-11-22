// studentc.hpp -- 컨테인먼트를 사용하는 Student 클래스를 정의한다
#ifndef STUDENTC_H_
#define STUDENTC_H_

#include <iostream>
#include <string>
#include <valarray>

class Student
{
private:
  typedef std::valarray<double> ArrayDb;
  std::string name;
  ArrayDb scores;
  // scores 출력을 위한 private 함수
   std::ostream & arr_out(std::ostream & os) const;
public:
// 생성자
  Student(void) : name("Null Student"), scores() {}
  explicit Student(const std::string & s)
    : name(s), scores() {}
  explicit Student(int n) : name("nully"), scores(n) {}
  Student(const std::string & s, int n) : name(s), scores(n) {}
  Student(const std::string & s, const ArrayDb & a)
    : name(s), scores(a) {}
  Student(const char * str, const double * pd, int n)
    : name(str), scores(pd, n) {}

// 파괴자
  ~Student(void) {}

// 멤버 함수
  double Average(void) const;
  const std::string & Name(void) const;
  double & operator[](int i);
  double operator[](int i) const;

// 프렌드
  friend std::istream & operator>>(std::istream & is, Student & stu);
  friend std::istream & getline(std::istream & is, Student & stu);
  friend std::ostream & operator<<(std::ostream & os, const Student & stu);
};

#endif
