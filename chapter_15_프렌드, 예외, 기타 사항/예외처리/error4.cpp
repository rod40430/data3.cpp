// error4.cpp -- 예외 클래스들을 사용한다
#include <iostream>
#include <cmath>
#include "exc_mean.hpp"

// 함수 원형
double hmean(double a, double b) throw(bad_hmean);
double gmean(double a, double b) throw(bad_gmean);

int main(void)
{
  using std::cout;
  using std::cin;
  using std::endl;

  double x, y, z;

  cout<<"두 수를 입력하십시오 : ";
  while (cin>>x>>y)
    {
      try
        {
          z = hmean(x, y);
          cout<<x<<", "<<y<<"의 조화평균은 "
            <<z<<"입니다.\n";
          z = gmean(x, y);
          cout<<x<<", "<<y<<"의 기하평균은 "
            <<z<<"입니다.\n";
          cout<<"다른 두 수를 입력하십시오(끝내려면 q) : ";
        }
        catch (bad_hmean & bg)
        {
          bg.mesg();
          cout<<"다시 하십시오 : ";
          continue;
        }
        catch (bad_gmean & bg)
        {
          cout<<bg.mesg();
          cout<<"사용된 두 값 : "<<bg.v1<<", "
            <<bg.v2<<endl;
          cout<<"죄송합니다. 더 이상 진행할 수 없습니다.\n";
          break;
        }
    }
  cout<<"프로그램을 종료합니다.\n";

  return 0;
}

double hmean(double a, double b) throw(bad_hmean)
{
  if (a == -b)
    throw bad_hmean(a, b);
  return 2.0 * a * b / (a + b);
}

double gmean(double a, double b) throw(bad_gmean)
{
  if (a < 0 || b < 0)
    throw bad_gmean(a, b);
  return std::sqrt(a * b);
}