// formore.cpp -- for 루프에 대한 보충
#include <iostream>

using namespace std;

const int ArSize = 16;  // 외부 선언의 예

int main(void)
{
  long long factorials[ArSize];
  factorials[1] = factorials[0] = 1LL;

  for (int i = 2; i < ArSize; i++)
    factorials[i] = i * factorials[i - 1];

  for(int i = 0; i < ArSize; i++)
    cout<<i<<" ! = "<<factorials[i]<<endl;
  
  return 0;
}