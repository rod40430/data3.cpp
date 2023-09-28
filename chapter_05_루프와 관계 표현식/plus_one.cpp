// plus_one.cpp -- 증가 연산자
#include <iostream>

using namespace std;

int main(void)
{
  int a = 20;
  int b = 20;

  cout<<"a   = "<<a<<" : b   = "<<b<<endl;
  cout<<"a++ = "<<a++<<" : ++b = "<<++b<<endl;  // a++ = 접미어 and ++b = 접두어
  cout<<"a   = "<<a<<" : b   = "<<b<<endl;
  
  return 0;
}