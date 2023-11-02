// string1.cpp -- String 클래스 메서드
#include <cstring>
#include "string1.hpp"

using std::cout;
using std::cin;

// static 클래스 멤버를 초기화한다

int String::num_strings = 0;

// static 메서드

int String::num_HowMany(void)
{
  return num_strings;
}

// 클래스 메서드

String::String(void)
{
  len = 1;
  str = new char[len];
  str[0] = '\0';
  num_strings++;
}

String::String(const char * s)
{
  len = strlen(s) + 1;
  str = new char[len];
  std::strcpy(str, s);
  num_strings++;
}

String::String(const String & st)
{
  len = st.len + 1;
  str = new char[len];
  std::strcpy(str, st.str);
  num_strings++;
}

String::~String(void)
{
  delete [] str;
  num_strings--;
}

// 오버로드 연산자 메서드

String & String::operator=(const String & st)
{
  if (this == &st)
    return *this;
  delete []str;
  len = st.len + 1;
  str = new char[len];
  std::strcpy(str, st.str);
  return *this;
}

String & String::operator=(const char * s)
{
  delete []str;
  len = std::strlen(s) + 1;
  str = new char[len];
  std::strcpy(str, s);
  return *this;
}

char & String::operator[](int i)
{
  return str[i];
}

const char & String::operator[](int i) const
{
  return str[i];
}

// 오버로드 연산자 프렌드

bool operator<(const String & st1, const String & st2)
{
  return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String & st1, const String & st2)
{
  return st2 < st1;
}

bool operator==(const String & st1, const String & st2)
{
  return (std::strcmp(st1.str, st2.str) == 0);
}

ostream & operator<<(ostream & os, const String & st)
{
  os<<st.str;
  return os;
}

istream & operator>>(istream & is, String & st)
{
  char temp[String::CINLIM];
  is.get(temp, String::CINLIM);
  if(is)
    st = temp;
  while (is && is.get() != '\n')
    continue;

  return is;
}