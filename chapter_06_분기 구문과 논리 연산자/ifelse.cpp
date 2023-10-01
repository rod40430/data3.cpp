// ifelse.cpp --  if else 구문
#include <iostream>

using namespace std;

int main(void)
{
  char ch;

  cout<<"타이핑하시면, 반복 수행하겠습니다.\n";
  cin.get(ch);

  while (ch != '.')
    {
      if (ch == '\n')
        cout<<ch;  // 개행 문자일 때 수행
      else 
        cout<<++ch;  // 그 밖의 문자일 때 수행

      cin.get(ch);
    }

  // ++ch 대신 ch + 1을 사용하면 어떻게 될까? = 형변환이 된다(형변환은 자강큰 자료형기준으로 변한다)
  cout<<"\n혼란스럽게 해서 죄송합니다.\n";
  
  return 0;
}