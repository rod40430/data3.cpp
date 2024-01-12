// rvref.cpp -- 간단한 rvalue 참조 예제
#include <iostream>

inline double f(double tf)
{
  return 5.0 * (tf - 32.0) / 9.0;
}

int main(void)
{
  using namespace std;

  double tc = 21.5;
  double && rd1 = 7.07;  // &&는 rvalue 참조 문법이다
  double && rd2 = 1.8 * tc + 32.0;
  double && rd3 = f(rd2);

  cout<<"tc value and address : "<<tc<<", "<<&tc<<endl;
  cout<<"rd1 value and address : "<<rd1<<", "<<&rd1<<endl;
  cout<<"rd2 value and address : "<<rd2<<", "<<&rd2<<endl;
  cout<<"rd3 value and address : "<<rd3<<", "<<&rd3<<endl;
  cin.get(); // 마지막 입럭을 받아야 종료

  return 0;
}
