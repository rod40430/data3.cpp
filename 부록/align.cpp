// align.cpp -- checking alignment
#include <iostream>

using namespace std;

struct things1
{
  char ch;
  int a;
  double x;
};

struct things2
{
  int a;
  double x;
  char ch;
};

int main(void)
{
  things1 th1;  // 16바이트
  things2 th2;  // 24바이트
  
  cout<<"char aligment : "<<alignof(char)<<endl;
  cout<<"int aligment : "<<alignof(int)<<endl;
  cout<<"double aligment : "<<alignof(double)<<endl;
  cout<<"things1 aligment : "<<alignof(things1)<<endl;
  cout<<"things2 aligment : "<<alignof(things2)<<endl;
  cout<<"things1 size : "<<sizeof(things1)<<endl;
  cout<<"things2 size : "<<sizeof(things2)<<endl;

  return 0;
}
