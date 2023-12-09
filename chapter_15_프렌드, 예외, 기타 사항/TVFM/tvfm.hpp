// tvfm.hpp -- 프렌드 멤버를 사용하는 Tv 클래스와 Remote 클래스
#ifndef TVFM_H_
#define TVFM_H_

class Tv;  // 사전 선언

class Remote
{
public:
  enum {Off, On};
  enum {MinVal, MaxVal = 20};
  enum {Antenna, Cable};
  enum {TV, VCR};
private:
  int mode;
public:
// 원형만
  Remote(int m = Tv) : mode(m) {}
  bool volup(Tv & t);
  bool voldown(Tv & t);
  bool onoff(Tv & t);
  void chanup(Tv & t);
  void chandown(Tv & t);
  void set_mode(Tv & t);
  void set_input(Tv & t);
  void setings(Tv & t, int c);
};

class Tv
{
public:
  friend void Remote::set_chan(Tv & t, int c);
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
}

inline bool Remote::volup(Tv & t) {return t.volup();}
inline bool Remote::voldown(Tv & t) {return t.voldown();}
inline void Remote::onoff(Tv & t) {t.onoff();}
inline void Remote::chanup(Tv & t) {t.chanup();}
inline void Remote::chandown(Tv & t) {t.chandown();}
inline void Remote::set_chan(Tv & t, int c) {channel = c;}
inline void Remote::set_mode(Tv & t) {t.set_mode();}
inline void Remote::set_input(Tv & t) {t.set_input();}

#endif
