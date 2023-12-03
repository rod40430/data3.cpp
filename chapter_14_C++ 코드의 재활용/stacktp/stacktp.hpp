// stacktp.hpp -- 스택 템플릿
#ifndef STACKTP_H_
#define STACKTP>H_

template <typename Type>
class Stack
{
private:
  enum {MAX = 10};  // 클래스용 상수
  Type items[MAX];  // 스택 항목들을 저장한다
  int top;  // 스택의 꼭대기 항목을 나타낸다
public:
// 생성자 및 파괴자
  Stack(void);
  ~Stack(void) {};
// 멤버 함수
  bool isempty(void);
  bool isfull(void);
  bool push(const Type & item);  // 스택에 항목을 추가한다
  bool pop(Type & item);  // 꼭대기 항목을 꺼내 item에 넣는다
};

template <typename Type>
Stack<Type>::Stack()
{
  top = 0;
}

template <typename Type>
bool Stack<Type>::isempty()
{
  return top == 0;
}

template <typename Type>
bool Stack<Type>::isfull()
{
  return top == MAX;
}

template <typename Type>
bool Stack<Type>::push(const Type & item)
{
  if (top < MAX)
  {
    items[top++] = item;
    return true;
  }
  else
    return false;
}

template <typename Type>
bool Stack<Type>::pop(Type & item)
{
  if (top > 0)
  {
    item = items[--top];
    return true;
  }
  else
    return false;
}

#endif
