// strfile.cpp -- 파일로부터 문자열들을 읽는다
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main(void)
{
  using namespace std;
  ifstream fin;
  fin.open("tobuy.txt");

  if (fin.is_open() == false)
  {
    cerr<<"파일을 열수 없습니다.\n";
    exit(EXIT_FAILURE);
  }
  
  string item;
  int count = 0;
  getline(fin, item, ':');

  while (fin)
    {
      ++count;
      cout<<count<<" : "<<item<<endl;
      getline(fin, item, ':');
    }
  cout<<"프로그램을 종료합니다.\n";
  fin.close();

  return 0;
}