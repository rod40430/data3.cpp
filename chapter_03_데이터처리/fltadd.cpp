// fltadd.cpp.cpp -- float형에서의 정밀도 손실 문제
#include <iostream>

using namespace std;

int main(void)
{
  float a = 2.34E+22f;
  float b = a + 1.0f;

  cout<<"a = "<<a<<endl;
  cout<<"b - a = "<<b - a<<endl;

  return 0;
}