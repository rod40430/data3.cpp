// fun_ptr.cpp -- 함수를 지시하는 포인터
#include <iostream>

using namespace std;

double gildong(int);
double moonsoo(int);

// 두 번째 매개변수는 int형을 매개변수로 취하는
// double형 함수를 지시하는 포인터이다
void estimate(int lines, double (*pt)(int));

int main(void)
{
  int code;

  cout<<"필요한 코드의 행 수를 입력하십시오 : ";
  cin>>code;

  cout<<"홍길동의 시간 예상 : \n";
  estimate(code, gildong);

  cout<<"박문수의 시간 예상 : \n";
  estimate(code, moonsoo);
  
  return 0;
}

double gildong(int Ins)
{
  return 0.05 * Ins;
}

double moonsoo(int Ins)
{
  return 0.03 * Ins + 0.0004 * Ins * Ins;
}

void estimate(int lines, double (*pf)(int))
{
  cout<<lines<<"행을 작성하는 데 ";
  cout<<(*pf)(lines)<<"시간이 걸립니다.\n";
}