#include <iostream>
using namespace std;

#define OK 0
#define ERROR -1

struct Node {
    double data;
    struct Node* next;
};

// 初始化单链表
int initList(Node*& L) {
    L = new Node;
    L->next = nullptr;
    return OK;
}

// 根据序号i查找数据
int getData(Node*& L, int i, double& data) {
    Node* p = L->next;
    int j = 1;
    while (p != nullptr && j < i) {
        p = p->next;
        j++;
    }
    if (p == nullptr || j > i)
        return ERROR;
    data = p->data;
    return OK;
}

// 根据数据查找结点指针
Node* locateNode(Node*& L, double data) {
    Node* p = L->next;
    while (p != nullptr && p->data != data)
        p = p->next;
    return p;
}

// 在位置i插入新结点
int insertNode(Node*& L, int i, Node* newNode) {
    Node* p = L;
    int j = 0;
    while (p != nullptr && j < i - 1)
        p = p->next;
    if (p == nullptr || j > i - 1)
        return ERROR;
    newNode->next = p->next;
    p->next = newNode;
    return OK;
}

// 删除第i个结点
int deleteNode(Node*& L, int i) {
    Node* p = L;
    int j = 0;
    while (p->next != nullptr && j < i - 1)
        p = p->next;
    if (p->next == nullptr || j > i - 1)
        return ERROR;
    // p此时指向第i-1个结点
    Node* q = p->next; // q指向第i个结点
    p->next = q->next;
    delete q;
}

int main() {
    Node* L;
    initList(L);
    double data;
    int a = getData(L, 1, data);
    cout << a;
}