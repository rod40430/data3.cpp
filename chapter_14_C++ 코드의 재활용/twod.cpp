// twod.cpp -- 2차원 배열 만들기
#include "arraytp.hpp"

int main(void)
{
  using std::cout;
  using std::endl;

  ArrayTP<int, 10> sums;
  ArrayTP<double, 10> aves;
  ArrayTP<ArrayTP<int, 5>, 10> twodee;

  int i, j;

  for (i = 0; i < 10; i++)
    {
      sums[i] = 0;
      for (j = 0; j < 5; j++)
        {
          twodee[i][j] = (i + 1) * (j + 1);
          sums[i] += twodee[i][j];
        }
      aves[i] = (double) sums[i] / 10;
    }

  for (i = 0; i < 10; i++)
    {
      for (j = 0; j < 5; j++)
        {
          cout.width(2);
          cout<<twodee[i][j]<<' ';
        }
      cout<<" : 합계 = ";
      cout.width(3);
      cout<<sums[i]<<", 평균 = "<<aves[i]<<endl;
    }

  cout<<"프로그램을 종료합니다.\n";

  return 0;
}