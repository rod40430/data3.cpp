// str2.cpp -- capacity()와 reserve()
#include <iostream>
#include <string>

int main(void)
{
  using namespace std;
  string empty;
  string small = "bit";
  string larger = "Elephants are a girl's best friend";

  cout<<"크기 : \n";
  cout<<"\tempty : "<<empty.size()<<endl;
  cout<<"\tsmall : "<<small.size()<<endl;
  cout<<"\tlarger : "<<larger.size()<<endl;
  cout<<"용량 : \n";
  cout<<"\tempty : "<<empty.capacity()<<endl;
  cout<<"\tsmall : "<<small.capacity()<<endl;
  cout<<"\tlarger : "<<larger.capacity()<<endl;

  empty.reserve(50);
  cout<<"empty.reserve(50) 이후 용량 : "
      <<empty.capacity()<<endl;

  return 0;
}