// mixtypes.cpp -- 일종의 형태 혼합
#include <iostream>

using namespace std;

typedef struct antarctica_years_end
{
  int year;
}aye;

int main(void)
{
  aye s01, s02, s03;
  s01.year = 1998;
  aye * pa = &s02;
  pa->year = 1999;
  aye trio[3];
  trio[0].year = 2003;

  cout<<trio->year<<endl;

  const aye * arp[3] = {&s01, &s02, &s03};
  cout<<arp[1]->year<<endl;
  const aye ** ppa = arp;
  auto ppb = arp;  // 자동 형태 추측
  // 또는 const aye **ppb = arp를 사용한다
  cout<<(*ppa)->year<<endl;
  cout<<(*(ppb + 1))->year<<endl;
  
  return 0;
}