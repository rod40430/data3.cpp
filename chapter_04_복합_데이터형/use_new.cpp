// use_new.cpp -- new 연산자 사용하기
#include <iostream>

using namespace std;

int main(void)
{
  int nights = 1001;
  int * pt = new int;
  *pt = 1001;

  cout<<"nights의 값 = "
    <<nights<<" : 메모리의 위치 "<<&nights<<endl;

  cout<<"int 형"
    <<"값 = "<<*pt<<" : 메모리의 위치 : "<<pt<<endl;

  double * pd = new double;
  *pd = 10000001.0;

  cout<<"double 형"
    <<"값 = "<<*pd<<" : 메모리의 위치 : "<<pd<<endl;
  cout<<"포인터 pd의 메모리 위치 : "<<&pd<<endl;
  cout<<"pt의 크기 = "<<sizeof(pt)<<endl;
  cout<<"*pt의 크기 = "<<sizeof(*pt)<<endl;
  
  cout<<"pd의 크기 = "<<sizeof(pd)<<endl;
  cout<<"*pd의 크기 = "<<sizeof(*pd)<<endl;
  
  return 0;
}