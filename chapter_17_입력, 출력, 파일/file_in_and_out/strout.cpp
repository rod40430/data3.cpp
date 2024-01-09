// strout.cpp -- 인코어 형식의 지정(출력)
#include <iostream>
#include <sstream>
#include <string>

int main(void)
{
  using namespace std;
  ostringstream outstr;

  string hdisk;
  cout<<"하드디스크의 모델명이 무엇입니까? ";
  getline(cin, hdisk);
  int cap;
  cout<<"하드디스크의 용량이 몇 GB입니까? ";
  cin>>cap;
  // 형식이 지정된 정보를 string 스트림에 써 놓는다
  outstr<<hdisk<<"하드디스크의 용량은 "
    <<cap<<"GB입니다.\n";
  string result = outstr.str();  // 결과를 저장한다 
  // outstr.str() 메서드를 사용하면 객체가 동결된다 즉 그것에 더 이상 정보를 써 넣을 수 없다
  cout<<result<<endl;  // 내용을 화면에 표시한다

  return 0;
}