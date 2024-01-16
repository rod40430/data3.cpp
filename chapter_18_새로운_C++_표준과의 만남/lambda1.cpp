// lambda1.cpp -- 저장된 변수 사용
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>

namespace 
{
  const long Size = 390000L;
}

int main(void)
{
  using std::cout;
  std::vector<int> numbers(Size);
  
  std::srand(std::time(0));
  std::generate(numbers.begin(), numbers.end(), std::rand);
  // 함수 포인터 사용
  cout<<"샘플 크기 = "<<Size<<'\n';

  // 람다 사용
  int count3 = std::count_if(numbers.begin(), numbers.end(),
  [](int x){return x % 3 == 0;});
  cout<<"3으로 나누어질 수 있는 개수 : "<<count3<<'\n';
  int count13 = 0;
  std::for_each(numbers.begin(), numbers.end(),
    [&count13](int x){count13 += x % 13 == 0;});
  cout<<"13으로 나누어질 수 있는 개수 : "<<count13<<'\n';

  // 간단한 람다 사용
  count3 = count13 = 0;
  std::for_each(numbers.begin(), numbers.end(),
    [&](int x){count3 += x % 3 == 0; count13 += x % 13 == 0;});
  cout<<"3으로 나누어질 수 있는 개수 : "<<count3<<'\n';
  cout<<"13으로 나누어질 수 있는 개수 : "<<count13<<'\n';

  return 0;
}