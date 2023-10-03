// cctypes.cpp -- ctype.h 라이브러리 사용
#include <iostream>
#include <cctype>                    // 문자 관련 함수들의 원형

using namespace std;

int main(void)
{
  cout<<"분석할 텍스트를 입력하십시오. "
    <<"입력의 끝을 0으로 표기하십시오.\n";

  char ch;
  int whitespace = 0;
  int digits = 0;
  int chars = 0;
  int punct = 0;
  int others = 0;

  cin.get(ch);                      // 첫 문자를 입력받는다
  while (ch != '0')                 // 종료 표시 문자인지 검사한다
    {
      if (isalpha(ch))              // 영문자인가?
        ++chars;
      else if (isspace(ch))         // 화이트스페이스인가?
        ++whitespace;
      else if (isdigit(ch))         // 숫자인가?
        ++whitespace;
      else if (ispunct(ch))         // 구두점인가?
        ++punct;
      else
        others++;

      cin.get(ch);                  // 다음 문자를 입력받는다
    }

  cout<<"알파뱃 문자 : "<<chars<<endl
    <<"화이트스페이스 : "<<whitespace<<endl
    <<"숫자 : "<<digits<<endl
    <<"구두점 : "<<punct<<endl
    <<"기타 : "<<others<<endl;
  
  return 0;
}
