// get_fun.cpp -- get()과 getline()을 사용한다
#include <iostream>

namespace 
{
  const int Limit = 255;
}

int main(void)
{
  using std::cout;
  using std::cin;
  using std::endl;

  char input[Limit];

  cout<<"getline()이 처리할 문자열을 입력하십시오 : \n";
  cin.getline(input, Limit, '#');
  cout<<"다음과 같이 입력하셨습니다 : \n";
  cout<<input<<"1단계 완료"<<endl;

  char ch;
  cin.get(ch);
  cout<<"다음 입력 문자는 "<<ch<<"입니다"<<endl;

  if (ch != '\n')
    cin.ignore(Limit, '\n');  // 그 줄 나머지를 읽고 버린다
  cout<<"get()이 처리할 문자열을 입력하십시오 : \n";
  cin.get(input, Limit, '#');
  cout<<"다음과 같이 입력하셨습니다 : \n";
  cout<<input<<"\n2단계 완료\n";

  cin.get(ch);
  cout<<"다음 입력 문자는 "<<ch<<"입니다"<<endl;

  return 0;
}