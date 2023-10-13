// cubes.cpp -- 일반 매개변수와 참조 매개변수
#include <iostream>

using namespace std;

double cube(double a);
double refcube(double &ra);

int main(void)
{
  double x = 3.0;

  cout<<cube(x);
  cout<<" = "<<x<<"의 세제곱\n";
  cout<<refcube(x);
  cout<<" = "<<x<<"의 세제곱\n";
  
  return 0;
}

double cube(double a)
{
  a *= a * a;
  return a;
}

double refcube(double &ra)
{
  ra *= ra * ra;
  return ra;
}