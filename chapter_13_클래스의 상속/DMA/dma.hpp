// dma.hpp -- 상속과 동적 메모리 대입
#ifndef DAM_H_
#define DAM_H_
#include <iostream>

// DMA를 사용하는 기초 클래스
class baseDMA
{
private:
  char * label;
  int rating;
public:
  baseDMA(const char * l = "null", int r = 0);
  baseDMA(const baseDMA & rs);
  virtual ~baseDMA(void);
  baseDMA & operator=(const baseDMA & rs);
  friend std::ostream & operator<<(std::ostream & os, const baseDMA & rs);
};

// DMA를 사용하지 않는 파생 클래스
// 파괴자가 필요 없다
// 암시적 복사 생성자를 사용한다
// 암시적 대입 연산자를 사용한다
class lacksDMA : public baseDMA
{
private:
  enum {COL_LEN = 40};
  char color[COL_LEN];
public:
  lacksDMA(const char * c = "blank", const char * l = "null", int r = 0);
  lacksDMA(const char * c, const baseDMA & rs);
  friend std::ostream & operator<<(std::ostream & os, const lacksDMA & ls);
};

// DMA를 사용하는 파생 클래스
class hasDMA : public baseDMA
{
private:
  char * style;
public:
  hasDMA(const char * s = "none" , const char * l = "null", int r = 0);
  hasDMA(const char * s, const baseDMA & rs);
  hasDMA(const hasDMA & hs);
  ~hasDMA(void);
  hasDMA & operator=(const hasDMA & hs);
  friend std::ostream & operator<<(std::ostream & os, const hasDMA & hs);
};

#endif