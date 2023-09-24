// address.cpp -- & 연산자로 주소를 알아낸다
#include <iostream>

using namespace std;

int main(void)
{
  int donuts = 6;
  double cups = 4.5;

  cout<<"donuts의 값 = "<<donuts
    <<", donuts의 주소 = "<<&donuts<<endl;

  cout<<"cups의 값 = "<<cups
    <<", cups의 주소 = "<<&cups<<endl;
  
  return 0;
}