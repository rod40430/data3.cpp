// secref.cpp -- 참조 변수의 정의와 사용
#include <iostream>

using namespace std;

int main(void)
{
  int rats = 101;
  int & rodents = rats;  // rodents는 참조 변수이다

  cout<<"rats = "<<rats;
  cout<<", rodents = "<<rodents<<endl;

  cout<<"rats의 주소 = "<<&rats<<endl;
  cout<<"rodents의 주소 = "<<&rodents<<endl;

  int dunnies = 50;
  rodents = dunnies;
  cout<<"dunnies = "<<dunnies<<endl;
  cout<<"rats = "<<rats<<endl;
  cout<<"rodents = "<<rodents<<endl;

  cout<<"dunnies의 주소 = "<<&dunnies<<endl;
  cout<<"rodents의 주소 = "<<&rodents<<endl;
  
  return 0;
}