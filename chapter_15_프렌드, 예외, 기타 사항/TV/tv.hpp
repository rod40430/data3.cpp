// tv.hpp -- Tv 클래스와 Remote 클래스
#ifndef TV_H_
#define TV_H_

class Tv
{
public:
  friend class Remote;  // Remote는 Tv의 private 부분에 접근할 수 있다.
  enum {Off, On};
  enum {MinVal, MaxVal = 20};
  enum {Antenna, Cable};
  enum {TV, DVD};

// 생성자
  Tv(int s = Off, int mc = 125)
    : state(s), volume(5), maxchannel(mc), chanel(2), mode(Cable), input(TV) {}
// 멤버 함수
  void onoff(void) {state = (state == On) ? Off : On;}
  bool ison(void) const {return state == On;}
  bool volup(void);
  bool voldown(void);
  void chanup(void);
  void chandown(void);
  void set_mode(void) {mode = (mode == Antenna) ? Cable : Antenna;}
  void set_input(void) {input = (input == TV) ? DVD : TV;}
  void setings(void) const;

private:
  int state;  // On 또는 Off
  int volume;  // 디지털 볼륨이라고 가정한다
  int maxchannel;  // 최대 채널 수
  int chanel;  // 현재 설정된 채널
  int mode;  // 지상파 방송 또는 케이블 방송
  int input;  // TV 입력 또는 DVD 입력
};

class Remote
{
private:
  int mode;  // TV 조정기 또는 DVD 조정기

public:
// 생성자
  Remote(int m = Tv::TV) : mode(m) {}
// 멤버 함수
  bool volup(Tv & t) {return t.volup();}
  bool voldown(Tv & t) {return t.voldown();}
  void onoff(Tv & t) {t.onoff();}
  void chanup(Tv & t) {t.chanup();}
  void chandown(Tv & t) {t.chandown();}
  void set_chan(Tv & t, int c) {return channel = c;}
  void set_mode(Tv & t) {t.set_mode();}
  void set_input(Tv & t) {t.set_input();}
};

#endif
