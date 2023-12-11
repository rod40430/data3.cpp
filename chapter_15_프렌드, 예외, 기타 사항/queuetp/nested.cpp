// nested.cpp -- 내포 클래스를 가지고 있는 큐를 사용한다
#include <iostream>
#include <string>
#include "queuetp.hpp"

int main(void)
{
  using std::string;
  using std::cin;
  using std::cout;

  QueueTP<string> cs(5);
  string temp;

  while (!cs.isfull())
    {
      cout<<"이름을 입력하십시오. 도착하신 순서대로 "
          <<"사은품을 드립니다.\n"
          <<"이름 : ";
      getline(cin, temp);
      cs.enqueue(temp);
    }
  cout<<"큐가 가득 찼으므로, 지금부터 사은품을 나누어 드리겠습니다.\n";

  while(!cs.isempty())
    {
      cs.dequeue(temp);
      cout<<temp<<"님! 감사합니다. 안녕히가십시오.\n";
    }

  return 0;
}