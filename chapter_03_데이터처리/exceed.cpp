// exceed.cpp -- 정수 한계값을 초과한다
#include <iostream>
#define ZERO 0
#include <climits>

int main(void)
{
  using namespace std;
  short Dohee = SHRT_MAX;
  unsigned short Insuk = Dohee;

  cout<<"도희의 계좌에는 "<<Dohee<<"원이 들어 있고, ";
  cout<<"인숙이의 게좌에도"<<Insuk<<"원이 들어 있다."<<endl;
  cout<<"각각의 게좌에 1원씩 입금한다."<<endl<<" 이제 ";

  Dohee++;
  Insuk++;
  cout<<"도희의 잔고는 "<<Dohee<<"원이 되었고, ";
  cout<<"인숙이의 잔고는 "<<Insuk<<"원이 되었다."<<endl;
  cout<<"이럴 수가! 도희가 나 몰래 대출을 했나?"<<endl;
  Dohee = ZERO;
  Insuk = ZERO;

  cout<<"도희의 계좌에는 "<<Dohee<<"원이 들어 있고, ";
  cout<<"인숙이의 게좌에도"<<Insuk<<"원이 들어 있다."<<endl;
  cout<<"각각의 게좌에 1원씩 인출한다."<<endl<<" 이제 ";
  Dohee--;
  Insuk--;

  cout<<"도희의 잔고는 "<<Dohee<<"원이 되었고, ";
  cout<<"인숙이의 잔고는 "<<Insuk<<"원이 되었다."<<endl;
  cout<<"이럴 수가! 인숙이가 복권에 당첨되었나?"<<endl;

  return 0;
}
