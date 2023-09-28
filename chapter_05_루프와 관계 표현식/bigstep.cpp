// bigstep.cpp -- count as directed
#include <iostream>

using namespace std;

int main(void)
{
  cout<<"정수를 하나 입력하십시오 : ";
  int by;
  cin>>by;
  cout<<"갱신 크기 "<<by<<"s : \n";

  for(int i = 0; i < 100; i = i + by)
    cout<<i<<endl;
  
  return 0;
}