#include <iostream>

using Stack = struct SNode*;
using ElementType = double;

struct SNode {
    ElementType data; // 指向动态分配的数组
    SNode* next;      // 栈顶指针
};

/*
 * S作为头结点，数据域不存储内容，只有指针域使用，指向的是栈顶元素。
 * 栈空则指针域为 nullptr 即 S->next == nullptr
 */

/* 构建头结点并返回指针 */
Stack createStack() {
    Stack S = new SNode;
    S->next = nullptr;
    return S;
}

/* 判断栈是否为空 */
bool isEmpty(Stack S) { return S->next == nullptr; }

/* 入栈 */
void push(ElementType X, Stack S) {
    SNode* newNode = new SNode;
    newNode->data = X;
    newNode->next = S->next;
    S->next = newNode;
}

/* 出栈 */
ElementType pop(Stack S) {
    if (isEmpty(S)) { /* 栈空 */
        std::cout << "the stack is empty\n";
        return NAN;
    }
    SNode* del = S->next;      // 要删除的结点
    ElementType X = del->data; // 取出栈顶元素
    S->next = del->next;       // 修改栈顶指针
    delete del;                // 释放结点空间
    return X;
}