// outfile.cpp -- 파일에 쓰기
#include <iostream>
#include <fstream>  // 파일 I/O를 위해

using namespace std;

int main(void)
{
  double d_price;
  double a_price;
  int year;
  char autombile[50];

  ofstream outFile;  // 출력을 위한 객체 생성
  outFile.open("carinfo.txt");  // 파일에 연결

  cout<<"자동차 메이커와 차종을 입력하시오 : ";
  cin.getline(autombile, 50);
  cout<<"연식을 입력하십시오 : ";
  cin>>year;
  cout<<"구입 가격을 입력하시오 : ";
  cin>>a_price;
  d_price = 0.913 * a_price;

  // cout으로 스크린에 정보를 디스플레이

  cout<<fixed;
  cout.precision(2);
  cout.setf(ios_base::showpoint);
  cout<<"메이커와 차종 : "<<autombile<<endl;
  cout<<"연식 : "<<year<<endl;
  cout<<"구입 가격 : $"<<a_price<<endl;
  cout<<"현재 가격 : $"<<d_price<<endl;

  // cout 대신 outFile을 사용하여 똑같은 일을 처리할 수 있다.
  outFile<<fixed;
  outFile.precision(2);
  outFile.setf(ios_base::showpoint);
  outFile<<"메이커와 차종 : "<<autombile<<endl;
  outFile<<"연식 : "<<year<<endl;
  outFile<<"구입 가격 : $"<<a_price<<endl;
  outFile<<"현재 가격 : $"<<d_price<<endl;

  outFile.close();  // 파일 처리 종료
  
  return 0;
}