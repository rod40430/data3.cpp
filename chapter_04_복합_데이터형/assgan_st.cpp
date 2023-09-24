// assgan_st.cpp -- 구조체 대입
#include <iostream>

using namespace std;

typedef struct inflatable
{
  double price;
  float volume;
  char name[20];
}table;

int main(void)
{
  table bouquet =
  {
    12.49,
    0.20,
    "sunflowers"
  };

  table choice;

  cout<<"bouquet : "<<bouquet.name<<" for $"
    <<bouquet.price<<endl;

  choice = bouquet;
  cout<<"choice : "<<choice.name<<" for $"
    <<choice.price<<endl;
  
  return 0;
}