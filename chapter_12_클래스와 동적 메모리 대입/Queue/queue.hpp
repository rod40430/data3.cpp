// queue.hpp -- 큐를 위한 인터페이스
#ifndef QUEUE_H_
#define QUEUE_H_
// 이 큐는 Customer 항목들을 포함하게 한다
class Customer
{
private:
  long arrive;  // 고객이 큐에 도착한 시간
  int processtime;  // 고객의 거래를 처리하는 시간
public:
  Customer(void) : arrive(0), processtime(0) {;}
  void set(long when);
  long when(void) const {return arrive;}
  int ptime(void) const {return processtime;}
};

typedef Customer Item;

class Queue
{
private:
// 클래스 사용 범위의 정의들
  // Node는 이 클래스에 지역적인, 내포된 구조체 정의이다
  struct Node
  {
    Item item;
    Node * next;
  };

  enum
  {
    Q_SIZE = 10
  };
// private 클래스 멤버들
  Node * front;  // Queue의 머리를 지시하는 포인터
  Node * rear;  // Queue의 꼬리를 지시하는 포인터
  int items;  // Queue에 있는 현재 항목 수
  const int qsize;  // Queue에 넣을 수 있는 최대 항목 수
  // public 복사를 방지하는 선언 정의
  Queue(const Queue & q) : qsize(0) {}
  Queue& operator=(const Queue & q) {return *this;}
public:
  Queue(int qs);
  ~Queue(void);
  bool isempty(void) const;
  bool isfull(void) const;
  int queuecount(void) const;
  bool enqueue(const Item & item);  // 항목을 꼬리에 추가한다
  bool dequeue(Item & item);  // 머리에서 항목을 삭제한다
};

#endif