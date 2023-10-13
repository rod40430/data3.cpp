// firstref.cpp -- 참조 변수의 정의와 사용
#include <iostream>

using namespace std;

int main(void)
{
  int rats = 101;
  int & rodents = rats;  // rodents는 참조 변수이다

  cout<<"rats = "<<rats;
  cout<<", rodents = "<<rodents<<endl;

  rodents++;
  cout<<"rats = "<<rats;
  cout<<", rodents = "<<rodents<<endl;

  cout<<"rats의 주소 = "<<&rats<<endl;
  cout<<"rodents의 주소 = "<<&rodents<<endl;
  
  return 0;
}