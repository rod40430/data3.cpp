// funtemp.cpp -- 함수 템플릿 사용하기
#include <iostream>

using namespace std;

// 함수 템플릿 원형
template <typename T>  // class 또는 typename
void Swap(T & a, T & b);

int main(void)
{ 
  int i = 10;
  int j = 20;
  cout<<"i, j = "<<i<<", "<<j<<endl;
  cout<<"컴파일러가 생성한 int형 교환기를 사용하면\n";
  Swap(i, j);  // void Swap(int &, int &)를 생성한다
  cout<<"이제 i, j = "<<i<<", "<<j<<endl<<endl;

  double x = 24.5;
  double y = 81.7;
  cout<<"x, y = "<<x<<", "<<y<<endl;
  cout<<"컴파일러가 생성한 double형 교환기를 사용하면\n";
  Swap(x, y);  // void Swap(double &, double &)를 생성한다
  cout<<"이제 x, y = "<<x<<", "<<y<<endl;
  
  return 0;
}

// 함수 템플릿 정의
template <typename T>
void Swap(T & a, T & b)
{
  T temp;  // temp는 T의 변수
  temp = a;
  a = b;
  b = temp;
}