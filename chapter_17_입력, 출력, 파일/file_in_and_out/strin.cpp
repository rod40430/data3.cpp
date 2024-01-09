// strin.cpp -- char형의 배열로부터 형식을 지정하여 읽는다
#include <iostream>
#include <sstream>
#include <string>

int main(void)
{
  using namespace std;
  string lit = "길섶 민들레 꽃시대롱 방울로 부풀어 "
                "여원 목 아프게 뺴어 들고 "
                "아가씨 실어 나를 바람 기다리누나.";
  istringstream instr(lit);  // 입력에 버퍼를 사용한다
  string word;
  while (instr>>word)  // 한 번에 한 단어씩 읽는다
    cout<<word<<endl;

  return 0;
}