// callable.cpp -- 호출 가능한 타입과 템플릿
#include "somedefs.hpp"

double dub(double x) {return 2.0 * x;}
double square(double x) {return x * x;}

int main(void)
{
  using std::cout;
  using std::endl;

  double y = 1.21;
  cout<<"함수 포인터 dub : \n";
  cout<<" "<<use_f(y, dub)<<endl;

  cout<<"함수 포인터 square : \n";
  cout<<" "<<use_f(y, square)<<endl;

  cout<<"함수 객체 Fp : \n";
  cout<<" "<<use_f(y, Fp(5.0))<<endl;

  cout<<"함수 객체 Fq : \n";
  cout<<" "<<use_f(y, Fq(5.0))<<endl;

  cout<<"람다 표현식 1 : \n";
  cout<<" "<<use_f(y, [](double u) {return u * u;})<<endl;

  cout<<"람다 표현식 2 : \n";
  cout<<" "<<use_f(y, [](double u) {return u + u / 2.0;})<<endl;

  return 0;
}