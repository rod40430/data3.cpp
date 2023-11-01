// strngbad.cpp -- StringBad 클래스의 메서드
#include <cstring>
#include "strngbad.hpp"

using std::cout;

// static 클래스 멤버를 초기화한다
int StringBad::num_strings = 0;

// 클래스 메서드

// C 스타일의 문자열로부터 StringBad를 생성한다
StringBad::StringBad(const char * s)
{
  len = std::strlen(s);  // 문자열 크기 저장
  str = new char[len + 1];  // 기억 공간을 대입한다
  std::strcpy(str, s);  // 포인터를 초기화한다
  num_strings++;  // 생성된 객체 수를 카운트한다
  cout<<num_strings<<" : \""<<str<<"\" 객체 생성\n";
}

StringBad::StringBad(void)  // 디폴트 생성자
{
  len = 4;
  str = new char[len];
  std::strcpy(str, "C++");  // 디폴트 문자열
  ++num_strings;
  cout<<num_strings<<" : \""<<str<<"\" 디폴트 객체 생성\n";
}

StringBad::~StringBad(void)
{
  cout<<"\""<<str<<"\" 객체 파괴.";
  --num_strings;
  cout<<"남은 객체 수 : "<<num_strings<<'\n';
  delete []str;
}

// 프렌드 함수
std::ostream & operator<<(std::ostream & os, const StringBad & st)
{
  os<<st.str;
  return os;
}