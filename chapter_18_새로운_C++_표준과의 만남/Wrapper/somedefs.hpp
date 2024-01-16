// somedefs.hpp
#include <iostream>

template <typename T, typename F>
T use_f(T v, F f)
{
  static int count = 0;
  count++;
  std::cout<<"use_f count = "<<count
    <<", &count = "<<&count<<std::endl;
  
  return f(v);  // 호출 가능한 타입을 표현하기 위해 매개변수 f를 사용한다
}

class Fp
{
private:
  double z_;
public:
  Fp(double z = 1.0) : z_(z) {}
  double operator()(double p) {return z_ * p;};
};

class Fq
{
private:
  double z_;
public:
  Fq(double z = 1.0) : z_(z) {}
  double operator()(double q) {return z_ + q;};
};
