// fileio.cpp -- 파일에 저장한다
#include <iostream>
#include <fstream>
#include <string>

int main(void)
{
  using namespace std;

  string filename;

  cout<<"새 파일을 위한 이름을 입력하십시오 : ";
  cin>>filename;

  // 새 파일을 위한 출력 스트림 객체를 fout이라는 이름으로 생성한다
  ofstream fout(filename.c_str());

  fout<<"비밀 번호 노출에 주의하십시오.\n";
  cout<<"비밀 번호를 입력하십시오 : ";
  float secret;
  cin>>secret;
  fout<<"귀하의 비밀 번호는 "<<secret<<"입니다.\n";
  fout.close();

  // 새파일을 위한 입력 스트림 객체를 fin이라는 이름으로 생성한다
  ifstream fin(filename.c_str());
  cout<<filename<<"파일의 내용은 다음과 같습니다 : \n";
  char ch;

  while (fin.get(ch))
    cout<<ch;
  cout<<" 프로그램을 종료합니다.\n";
  fin.close();

  return 0;
}
