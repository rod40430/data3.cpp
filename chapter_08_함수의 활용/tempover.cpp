// tempover.cpp -- 템플릿 오버로딩
#include <iostream>

using namespace std;

template <typename T>
void ShowArray(T arr[], int n);  // 템플릿 A

template <typename T>
void ShowArray(T * arr[], int n);  // 템플릿 B

typedef struct
{
  char name[50];
  double amount;
} debts;

int main(void)
{ 
  int things[6] = {13, 31, 103, 301, 310, 130};
  debts mr_E[3] =
  {
    {"Ima woife", 2400.0},
    {"Ura Foxe", 1300.0},
    {"Iby Stout", 1800.0}
  };
  double * pd[3];

  // 포인터들을 배열 mr_E에 있는 구조체들의 amount 멤버로 설정한다
  for (int i = 0; i < 3; i++)
    pd[i] = &mr_E[i].amount;

  cout<<"Mr. E의 재산 목록 : \n";
  // things는 int형의 배열이다
  ShowArray(things, 6);  // 템플릿 A를 사용한다
  cout<<"Mr. E의 재우 목록 : \n";
  // pd는 double형을 지시하는 포인터들의 배열이다
  ShowArray(pd, 3);  // 더 특수화된 템플릿 B를 사용한다
  
  return 0;
}

template <typename T>
void ShowArray(T arr[], int n)
{
  cout<<"템플릿 A\n";
  for (int i = 0; i < n; i++)
    cout<<arr[i]<<' ';
  cout<<endl;
}

template <typename T>
void ShowArray(T * arr[], int n)
{
  cout<<"템플릿 B\n";
  for (int i = 0; i < n; i++)
    cout<<*arr[i]<<' ';
  cout<<endl;
}