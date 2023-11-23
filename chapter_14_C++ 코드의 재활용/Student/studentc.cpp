// studentc.cpp -- 컨테인먼트를 사용하는 Student 클래스
#include "studentc.hpp"

using std::istream;
using std::ostream;
using std::endl;
using std::string;

// public 메서드들
double Student::Average(void) const
{
  if (scores.size() > 0)
    return scores.sum() / scores.size();
  else
    return 0;
}

const string & Student::Name(void) const
{
  return name;
}

double & Student::operator[](int i)
{
  return scores[i];  // valarray<double>::operator[]() 사용
}

double Student::operator[](int i) const
{
  return scores[i];
}

// private 메서드
ostream & Student::arr_out(ostream & os) const
{
  int i;
  int lim = scores.size();
  if (lim > 0)
  {
    for (i = 0; i < lim; i++)
      {
        os << scores[i] << " ";
        if (i % 5 == 4)
          os << endl;
      }
    if (i % 5 != 0)
      os << endl;
  }
  else
    os << "빈 배열";
  return os;
}

// 프렌드

// operator>>()의 string 버전을 사용한다
istream & operator>>(istream & is, Student & stu)
{
  is >> stu.name;
  return is;
}

// string friend getline(ostream &, const string &)을 사용한다
istream & getline(istream & is, Student & stu)
{
  getline(is, stu.name);
  return is;
}

// operator<<()의 string 버전을 사용한다
ostream & operator<<(ostream & os, const Student & stu)
{
  os << stu.name << "학생의 성적표 : \n";
  stu.arr_out(os);  // scores를 위해 private 메서드 사용
  return os;
}