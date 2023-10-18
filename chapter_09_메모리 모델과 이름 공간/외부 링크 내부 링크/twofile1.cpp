// twofile1.cpp -- 외부 링크와 내부 링크를 가지는 변수
#include <iostream>

using namespace std;

int tom = 3;  // 외부 변수를 정의한다
int dick = 30;  // 외부 변수를 정의한다

static int harray = 300;  // 정적 변수, 내부 링크

// 함수 원형
void remote_access(void);

int main(void)  // 전역 변수를 사용한다
{ 
  cout<<"main()이 보고하는 세 변수의 주소 : \n";
  cout<<&tom<<" = &tom\n";
  cout<<&dick<<" = &dick\n";
  cout<<&harray<<" = &harray\n";

  remote_access();
  
  return 0;
}