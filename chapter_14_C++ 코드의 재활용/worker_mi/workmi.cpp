// workmi.cpp -- 다중 상속
// workermi.cpp와 함께 컴파일한다
#include "workermi.hpp"
#include <cstring>
#include <iostream>

namespace {
const int SIZE = 5;
}

int main(void) {
  using std::cin;
  using std::cout;
  using std::endl;
  using std::strchr;

  Worker *lolas[SIZE];

  int ct;

  for (ct = 0; ct < SIZE; ++ct) {
    char choice;
    cout << "직종을 입력하십시오 : \n";
    cout << "W : 웨이터           S : 가수    ";
    cout << "T : 가수 겸 웨이터    Q : 종료\n";
    cin >> choice;
    while (strchr("WSTQ", choice) == NULL) {
      cout << "W, S, T, Q 중에서 하나를 선택하십시오 : \n";
      cin >> choice;
    }
    
    if (choice == 'Q')
      break;
    
    switch (choice) {
    case 'W':
      lolas[ct] = new Waiter;
      break;
    case 'S':
      lolas[ct] = new Singer;
      break;
    case 'T':
      lolas[ct] = new SingingWaiter;
      break;
    }
    while (cin.get() != '\n')
      continue;
    lolas[ct]->Set();
  }

  cout << "\n사원 현황은 다음과 같습니다 : \n";
  int i;
  for (i = 0; i < ct; ++i) {
    cout << endl;
    lolas[i]->Show();
  }

  for (i = 0; i < ct; ++i)
    delete lolas[i];

  cout << "프로그램을 종료합니다.\n";

  return 0;
}