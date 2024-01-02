// setf.cpp -- setf()를 사용하여 출력 형식 지정을 제어한다
#include <iostream>

int main(void)
{
  using std::cout;
  using std::endl;
  using std::ios_base;

  int temperature = 63;

  cout<<"오늘의 수온 : ";
  cout.setf(ios_base::showpos);  // + 출력
  cout<<temperature<<endl;

  cout<<"프로그래머들에게 그 값은\n";
  cout<<std::hex<<temperature<<endl;
  cout.setf(ios_base::uppercase);  // 16진수 대문자 출력
  cout.setf(ios_base::showbase);  // 출력 진법에 표시 접두어(0(8진법), 0x(16진법)) 사용
  cout<<"또는\n";
  cout<<temperature<<endl;
  cout<<true<<"!의 값은 ";
  cout.setf(ios_base::boolalpha);  // true와 false로 입력하고 출력한다
  cout<<true<<"이다.\n";

  return 0;
}