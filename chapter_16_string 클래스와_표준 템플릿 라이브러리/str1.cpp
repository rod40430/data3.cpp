// str1.cpp -- string 클래스를 소개한다
#include <iostream>
#include <string>
// string 생성자들을 사용한다

int main(void)
{
  using namespace std;
  string one("Lottery Winner!");
  cout<<one<<endl;
  
  string two(20, '$');
  cout<<two<<endl;
  
  string three(one);
  cout<<three<<endl;
  one += "Oops!";
  cout<<one<<endl;
  two = "Sorry! That was";
  three[0] = 'P';
  
  string four;
  four = two + three;
  cout<<four<<endl;
  
  char alls[] = "All's well that ends well!";
  string five(alls, 20);
  cout<<five<<"!\n";
  
  string six(alls + 6, alls + 10);  // alls의 6번째부터 10번째 까지
  cout<<six<<", ";
  
  string seven(&five[6], &five[10]);  // five의 6번째부터 10번째 까지
  cout<<seven<<endl;
  
  string eigth(four, 7, 16);  // four 7번째부터 시작해서 16번째까지
  cout<<eigth<<"in motion!"<<endl;

  return 0;
}
