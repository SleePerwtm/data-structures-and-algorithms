#include <iostream>

using ElementType = double;

const int kMaxSize = 100;

class ArrayQueue {
  private:
    ElementType data[kMaxSize];
    int front;
    int rear;

  public:
    bool isFull() const { return (rear + 1) % kMaxSize == front; }

    bool isEmpty() const { return front == rear; }

    /* 入队（队尾） */
    void push(ElementType val) {
        if (isFull()) {
            std::cerr << "Queue is full!\n";
            return;
        }
        data[rear] = val;             // 将元素添加到队尾
        rear = (rear + 1) % kMaxSize; // 循环队列的关键
    }

    /* 出队 */
    ElementType pop() {
        if (isEmpty()) {
            std::cerr << "Queue is empty!\n";
            return NAN;
        }
        ElementType temp = data[front]; // 获取队头元素
        front = (front + 1) % kMaxSize; // 循环队列的关键
        return temp;                    // 返回出队元素
    }

    /* 获取队头元素 */
    ElementType peek() {
        if (isEmpty()) {
            std::cerr << "Queue is empty!\n";
            return NAN;
        }
        return data[front];
    }
};