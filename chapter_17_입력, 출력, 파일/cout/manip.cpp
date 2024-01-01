// manip.cpp -- 출력 형식 조정자를 사용한다
#include <iostream>

int main(void)
{
  using namespace std;
  cout<<"하나의 정수를 입력하십시오 : ";
  int n;
  cin>>n;

  cout<<"n    n * n\n";
  cout<<n<<"    "<<n*n<<"(10진법)\n";

  // 16진법 모드로 설정
  cout<<hex;
  cout<<n<<"    ";
  cout<<n*n<<"(16진법)\n";

  // 8진법 모드로 설정
  cout<<oct<<n<<"    "<<n * n<<"(8진법)\n";

  // 조정자를 호추하는 다른 방법
  dec(cout);
  cout<<n<<"    "<<n * n<<"(10진법)\n";

  return 0;
}
