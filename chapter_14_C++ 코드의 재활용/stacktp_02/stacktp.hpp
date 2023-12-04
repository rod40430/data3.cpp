// stacktp.hpp -- 수정된 stack 템플릿
#ifndef STACKTP_H_
#define STACKTP>H_

template <typename Type>
class Stack
{
private:
  enum {SIZE = 10};  // default
  Type * items;  // 스택 항목들을 저장한다
  int stacksize;
  int top;  // 스택의 꼭대기 항목을 나타낸다
public:
// 생성자 및 파괴자
  explicit Stack(int ss = SIZE);
  Stack(const Stack & st);
  ~Stack(void) {delete [] items;}
// 멤버 함수
  bool isempty(void) {return top == 0;}
  bool isfull(void) {return top == stacksize;}
  bool push(const Type & item);  // 스택에 항목을 추가한다
  bool pop(Type & item);  // 꼭대기 항목을 꺼내 item에 넣는다

  Stack & operator=(const Stack & st);
};

template <typename Type>
Stack<Type>::Stack(int ss) : stacksize(ss), top(0)
{
  items = new Type[stacksize];
}

template <typename Type>
Stack<Type>::Stack(const Stack & st)
{
  stacksize = st.stacksize;
  top = st.top;
  items = new Type[stacksize];
  for (int i = 0; i < top; i++)
    items[i] = st.items[i];
}

template <typename Type>
bool Stack<Type>::push(const Type & item)
{
  if (top < stacksize)
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

template <typename Type>
Stack<Type> & Stack<Type>::operator=(const Stack<Type> & st)  // 리턴형 또는 사용 범위 결정 연산자를 쓸땐 Stack
{                                          // <Type>으로 풀네임을 사용해야한다. /그냥 풀네임쓰기!
  if (this == &st)
    return 0;
  delete [] items;
  stacksize = st.stacksize;
  items = new Type[stacksize];
  for (int i = 0; i < stacksize; ++i)
    items[i] = st.items[i];

  return *this;
}

#endif