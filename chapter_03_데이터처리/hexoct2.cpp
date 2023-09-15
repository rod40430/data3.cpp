// hexoct1.cpp -- 값을 16진수와 8진수로 디스플레이한다
#include <iostream>

using namespace std;

int main(void)
{
  int chest = 42;  // 10진 정수형 상수
  int waist = 42;  // 16진 정수형 상수
  int inseam = 42;  // 8진 정수형 상수

  cout<<"손님 몸매는 한마디로 끝내 줍니다!\n";
  cout<<"가슴둘래"<<chest<<" (10진수) "<<endl;
  cout<<hex;  // 진법을 바꾸는 조정자 16진수
  cout<<"허리둘래"<<waist<<" (16진수) "<<endl;;
  cout<<oct;  // 진법을 바꾸는 조정자 8진수
  cout<<"인심길이"<<inseam<<" (8진수) "<<endl;;
  cout<<dec;  // 진법을 바꾸는 조정자 10진수

  return 0;
}