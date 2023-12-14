// newexcp.cpp -- bad_alloc 예외 처리
#include <iostream>
#include <new>
#include <cstdlib>
using namespace std;

struct Big
{
  double stuff[20000000000000];
};

int main(void)
{
  Big * pb;

  try
    {
      cout<<"큰 메모리 블록 대입을 요청하고 있습니다.\n";
      pb = new Big[9999];
      cout<<"메모리 블록 대입 요청이 거부되었습니다.\n";
    }
    catch (bad_alloc & ba)
    {
      cout<<"에외가 감지되었습니다!\n";
      cout<<ba.what()<<endl;
      exit(EXIT_FAILURE);
    }
  cout<<"메모리 블록이 성공적으로 대입되었습니다.\n";
  cout<<pb[0].stuff[0]<<endl;
  delete []pb;

  return 0;
}