// iomanip.cpp -- iomanip의 조정자들을 사용한다
// 어떤 시스템에서는 링커에게 수학 라이브러리를 명시적으로 지시해야 한다
#include <iostream>
#include <iomanip>
#include <cmath>

int main(void)
{
  using namespace std;
  // 새로운 표준 조정자를 사용한다
  cout<<fixed<<right;

  // iomanip의 조정자들을 사용한다
  cout<<setw(6)<<"N"<<setw(15)<<"제곱근"
      <<setw(20)<<"네제곱근\n";

  double root;
  for (int n = 10; n <= 100; n += 10)
    {
      root = sqrt(double(n));
      cout<<setw(6)<<setfill('.')<<n<<setfill(' ')
          <<setw(12)<<setprecision(3)<<root
          <<setw(14)<<setprecision(4)<<sqrt(root)
          <<endl;
    }

  return 0;
}