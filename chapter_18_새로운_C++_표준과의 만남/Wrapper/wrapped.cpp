// wrapped.cpp -- 인자로 함수 래퍼 사용
#include "somedefs.hpp"
#include <functional>

double dub(double x) { return 2.0 * x; };
double square(double x) { return x * x; };

int main(void)
{
  using std::cout;
  using std::endl;
  using std::function;

  double y = 1.21;
  function<double(double)> ef1 = dub;
  function<double(double)> ef2 = square;
  function<double(double)> ef3 = Fp(10.0);
  function<double(double)> ef4 = Fq(10.0);
  function<double(double)> ef5 = [](double u) { return u * u; };
  function<double(double)> ef6 = [](double u) { return u + u / 2.0; };

  cout<<"함수 포인터 dub : \n";
  cout<<" "<<use_f(y, ef1)<<endl;

  cout<<"함수 포인터 square : \n";
  cout<<" "<<use_f(y, ef2)<<endl;

  cout<<"함수 객체 Fp : \n";
  cout<<" "<<use_f(y, ef3)<<endl;

  cout<<"함수 객체 Fq : \n";
  cout<<" "<<use_f(y, ef4)<<endl;

  cout<<"람다 표현식 1 : \n";
  cout<<" "<<use_f(y, ef5)<<endl;

  cout<<"람다 표현식 2 : \n";
  cout<<" "<<use_f(y, ef6)<<endl;

  return 0;
}