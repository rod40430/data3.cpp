// queuetp.hpp -- 내포 클래스를 사용하는 큐 템플릿
#ifndef QUEUETP_H_
#define QUEUETP_H_

template <class Item>
class QueueTP
{
private:
  enum {Q_SIZE = 10};
  // Node는 내포 클래스 정의이다
  class Node
  {
  public:
    Item item;
    Node * next;
    Node(const Item & i) : item(i), next(nullptr) {}
  };
  Node * front;
  Node * rear;
  int items;
  const int qsize;
  QueueTP(const QueueTP & q) : qsize(0) {}
  QueueTP & operator=(const QueueTP & q) {return *this;}
public:
// 생성자 및 파괴자
  QueueTP(int qs = Q_SIZE);
  ~QueueTP(void);
// 멤버 함수
  bool isempty(void) const
  {
    return items == 0;
  }
  bool isfull(void) const
  {
    return items == qsize;
  }
  int queuecount(void) const
  {
    return items;
  }
  bool enqueue(const Item & item);
  bool dequeue(Item & item);
};

// QueueTP 메서드들
template <typename Item>
QueueTP<Item>::QueueTP(int qs)
  : qsize(qs)
{
  front = rear = 0;
  items = 0;
}

template <typename Item>
QueueTP<Item>::~QueueTP(void)
{
  Node * temp;
  while (front != 0)
    {
      temp = front;
      front = front->next;
      delete temp;
    }
}

// 큐에 항목을 추가한다
template <typename Item>
bool QueueTP<Item>::enqueue(const Item & item)
{
  if (isfull())
    return false;
  Node * add = new Node(item);
  // 실패하면, new 연산자는 std::bad_alloc 예외를 발생시킨다
  items++;
  if (front == 0)
    front = add;
  else
    rear->next = add;
  rear = add;
  return true;
}

// 머리 항목을 item 변수에 넣고 큐에서 삭제한다
template <typename Item>
bool QueueTP<Item>::dequeue(Item & item)
{
  if (front == 0)
    return false;
  item = front->item;
  items--;
  Node * temp = front;
  front = front->next;
  delete temp;
  if (items == 0)
    rear = 0;
  return true;
}

#endif
