// vslice.cpp -- initializer_list를 사용한다 (C++11 feature)
#include <iostream>
#include <initializer_list>

double sum(std::initializer_list<double> il);
double average(const std::initializer_list<double> & ril);

int main(void)
{
  using std::cout;

  cout<<"목록 1 : 합계 = "<<sum({2, 3, 4})
    <<", 평균 = "<<average({2, 3, 4})<<'\n';
  std::initializer_list<double> dl = {1.1, 2.2, 3.3, 4.4, 5.5};
  cout<<"목록 2 : 합계 = "<<sum(dl)
    <<", 평균 = "<<average(dl)<<'\n';
  dl = {16.0, 25.0, 36.0, 40.0, 64.0};
  cout<<"목록 3 : 합계 = "<<sum(dl)
    <<", 평균 = "<<average(dl)<<'\n';
  
  return 0;
}

double sum(std::initializer_list<double> il)
{
  double tot = 0;
  for (auto x : il)
    tot += x;

  return tot;
}

double average(const std::initializer_list<double> & ril)
{
  double tot = sum(ril);

  return tot / ril.size();
}