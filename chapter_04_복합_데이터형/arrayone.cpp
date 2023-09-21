// arrayone.cpp -- 정수형의 작은 배열
#include <iostream>

using namespace std;

int main(void)
{
  int yams[3];

  yams[0] = 7;
  yams[1] = 8;
  yams[2] = 6;

  int yamcosts[3] = {200, 300, 50};

  cout<<"고구마 합계 = ";
  int sum = 0;
  for (int i = 0; i < sizeof(yams) / sizeof(int); i++)
    sum += yams[i];
  
  cout<<sum<<endl;
  cout<<yams[1]<<"개가 들어 있는 포장은 ";
  cout<<"개당 "<<yamcosts[1]<<"원씩입니다.\n";
  
  int total = 0;
    for (int i = 0; i < sizeof(yams) / sizeof(int); i++)
      total += yams[i] * yamcosts[i];
  
  cout<<"세 포장의 총 가격은 "<<total<<"원입니다.\n";
  cout<<"\nyams 배열의 크기는 "<<sizeof yams;
  cout<<"바이트입니다.\n";
  cout<<"원소 하나의 크기는 "<<sizeof yams[0];
  cout<<"바이트입니다.\n";
  
  return 0;
}
