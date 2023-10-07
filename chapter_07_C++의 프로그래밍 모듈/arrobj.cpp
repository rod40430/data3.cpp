// arrobj.cpp -- C++11의 array 객체에 대한 기능
#include <iostream>
#include <string>
#include <array>

using namespace std;

const int Seasons = 4;
const array<string, Seasons> Sname =
  {"Spring", "Summer", "Fall", "Winter"};

// array 객체를 수정하는 기능
void fill(array<double, Seasons> * pa);
// 수정하지 않고 객체를 사용하는 기능
void show(array<double, Seasons> pa);

int main(void)
{
  array<double, Seasons> expenses;
  
  fill(&expenses);
  show(expenses);
  
  return 0;
}

void fill(array<double, Seasons> * pa)
{
  for (int i = 0; i < Seasons; ++i)
    {
      cout<<Sname[i]<<"에 소요되는 비용 : ";
      cin>>(*pa)[i];
    }
}

void show(array<double, Seasons> pa)
{
  double total = 0.0;
  cout<<"\n계절별 비용\n";

  for (int i = 0; i <Seasons; ++i)
    {
      cout<<Sname[i]<<" : $"<<pa[i]<<endl;
      total += pa[i];
    }
  cout<<"총 비용 : $"<<total<<endl;
}