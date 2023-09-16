// morechar.cpp -- char형과 int형의 비교
#include <iostream>

using namespace std;

int main(void)
{
  char ch = 'M';
  int i = ch;
  cout<<ch<<"의 ASCII 코드는 "<<i<<"입니다."<<endl;

  cout<<"이 문자 코드에 1을 더해 보겠습니다."<<endl;
  ch++;
  i = ch;
  cout<<ch<<"의 ASCII 코드는 "<<i<<"입니다."<<endl;

  cout<<"cout.put(ch)를 사용하여 char형 변수 ch를 화면에 출력 : ";
  cout.put(ch);

  cout.put('!');

  cout<<endl<<"종료"<<endl;

  return 0;
}