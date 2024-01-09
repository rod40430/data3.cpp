// random.cpp -- 2진 파일에 임의 접근
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

inline void eatline()
{
  while (std::cin.get() != '\n')
    continue;
}

struct planet
{
  char name[20];
  double population;
  double g;
};

namespace 
{
  const int LIM = 20;
  const char * file = "planets.dat";
}

int main(void)
{
  using namespace std;

  planet pl;
  cout<<fixed;

  // 초기의 내용을 화면에 표시한다
  fstream finout;
  finout.open(file, ios_base::in | ios_base::out | ios_base::binary);  // 2진 파일
  int ct = 0;
  if (finout.is_open())
  {
    finout.seekg(0);
    cout<<file<<"파일의 현재 내용은 다음과 같습니다 : \n";
    while (finout.read((char *) & pl, sizeof pl))
      {
        cout<<ct++<<setw(LIM)<<pl.name<<" : "
            <<setprecision(0)<<setw(12)<<pl.population
            <<setprecision(2)<<setw(6)<<pl.g<<endl;
      }
    if (finout.eof())
      finout.clear();
    else
    {
      cerr<<file<<"파일을 읽다가 에러 발생.\n";
      exit(EXIT_FAILURE);
    }
  }
  else
  {
    cerr<<file<<"파일을 열 수 없습니다. 종료\n";
    exit(EXIT_FAILURE);
  }

  cout<<"수정할 레코드 번호를 입력하십시오 : ";
  long rec;
  cin>>rec;
  eatline();
  if (rec < 0 || rec >= ct)
  {
    cerr<<"잘못된 레코드 번호입니다. 종료.\n";
    exit(EXIT_FAILURE);
  }
  streampos place = rec * sizeof pl;
  finout.seekg(place);
  if (finout.fail())
  {
    cerr<<"레코드를 찾다가 에러 발생.\n";
    exit(EXIT_FAILURE);
  }
  

  // 새로운 데이터를 추가한다
  ofstream fout(file, ios_base::out | ios_base::app | ios_base::binary);
  if (!fout.is_open())
  {
    cerr<<"출력을 위해 "<<file<<"파일을 열 수 없습니다.\n";
    exit(EXIT_FAILURE);
  }
  finout.read((char *) & pl, sizeof pl);
  cout<<"현재 레코드의 내용 : \n";
  cout<<rec<<setw(LIM)<<pl.name<<" : "
  <<setprecision(0)<<setw(12)<<pl.population
  <<setprecision(2)<<setw(6)<<pl.g<<endl;
  if (finout.eof())
    finout.clear();

  cout<<"행성의 이름을 입력하십시오 : ";
  cin.get(pl.name, LIM);
  eatline();
  cout<<"행성의 인구를 입력하십시오 : ";
  cin>>pl.population;
  cout<<"행성의 중력가속도를 입력하십시오 : ";
  cin>>pl.g;
  finout.seekg(place);
  finout.write((char *) & pl, sizeof pl)<<flush;
  if (finout.fail())
  {
    cerr<<"쓰다가 에러 발생.\n";
    exit(EXIT_FAILURE);
  }

  ct = 0;
  finout.seekg(0);

  cout<<file<<"파일의 개정된 내용은 다음과 같습니다 : \n";
  while (finout.read((char *) & pl, sizeof pl))
  {
    cout<<ct++<<setw(LIM)<<pl.name<<" : "
    <<setprecision(0)<<setw(12)<<pl.population
    <<setprecision(2)<<setw(6)<<pl.g<<endl;
  }
  finout.close();
  cout<<"프로그램을 종료합니다.\n";

  return 0;
}