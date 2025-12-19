#include <iostream>

using ElementType = double;

class LinkedListQueue {
  private:
    struct Node {
        ElementType data;
        Node* next;
        Node() : next(nullptr) {}
        Node(ElementType val) : data(val), next(nullptr) {}
    };

    Node* front;
    Node* rear;

  public:
    LinkedListQueue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() const { return front == nullptr; }

    /* 入队 */
    void push(ElementType val) {
        Node* newNode = new Node{val};
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    /* 出队 */
    ElementType pop() {
        if (isEmpty()) {
            std::cerr << "Queue is empty!\n";
            return NAN;
        }
        ElementType temp = front->data;
        Node* del = front;
        if (front == rear) { /* 只剩一个节点，删除后需要更新front和rear指针 */
            front = rear = nullptr;
        } else { /* 多于一个节点，只更新front指针 */
            front = front->next;
        }
        delete del;
        return temp;
    }

    /* 获取队首元素 */
    ElementType peek() {
        if (isEmpty()) {
            std::cerr << "Queue is empty!\n";
            return NAN;
        }
        return front->data;
    }
};