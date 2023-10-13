// swaps.cpp -- 참조를 이용한 교환과 포인터를 이용한 교환
#include <iostream>

using namespace std;

void swapr(int & a, int & b);
void swapp(int * p, int * q);
void swapv(int a, int b);


int main(void)
{
  int wallet1 = 3000;
  int wallet2 = 3500;

  cout<<"지갑 1 = "<<wallet1<<"원\n";
  cout<<"지갑 2 = "<<wallet2<<"원\n\n";

  cout<<"참조를 이용하여 내용들을 교환 : \n";
  swapr(wallet1, wallet2);  // 변수를 전달
  cout<<"지갑 1 = "<<wallet1<<"원\n";
  cout<<"지갑 2 = "<<wallet2<<"원\n\n";

  cout<<"포인터를 이용하여 내용들을 다시 교환 : \n";
  swapp(&wallet1, &wallet2);  // 변수의 주소를 전달
  cout<<"지갑 1 = "<<wallet1<<"원\n";
  cout<<"지갑 2 = "<<wallet2<<"원\n\n";

  cout<<"값으로 전달하여 내용 교환 시도 : \n";
  swapv(wallet1, wallet2);  // 변수의 값을 전달
  cout<<"지갑 1 = "<<wallet1<<"원\n";
  cout<<"지갑 2 = "<<wallet2<<"원\n\n";
  
  return 0;
}

void swapr(int & a, int & b)  // 참조를 이용하여 교환
{
  int temp;

  temp = a;
  a = b;
  b = temp;
}

void swapp(int * a, int * b)  // 포인터를 이용하여 교환
{
  int temp;

  temp = *a;
  *a = *b;
  *b = temp;
}

void swapv(int a, int b)  // 값을 전달하여 교환 시도
{
  int temp;

  temp = a;
  a = b;
  b = temp;
}