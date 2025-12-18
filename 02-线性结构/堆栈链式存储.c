#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define bool _Bool
#define true 1
#define false 0

typedef struct SNode* Stack;
typedef double ElementType;

struct SNode {
    ElementType data;   // 指向动态分配的数组
    struct SNode* next; // 栈顶指针
};

/*
 * S作为头结点，数据域不存储内容，只有指针域使用，指向的是栈顶元素。
 * 栈空则指针域为 NULL 即 S->next == NULL
 */

/* 构建头结点并返回指针 */
Stack createStack() {
    Stack S = malloc(sizeof(struct SNode));
    S->next = NULL;
    return S;
}

/* 判断栈是否为空 */
bool isEmpty(Stack S) { return S->next == NULL; }

/* 入栈 */
void push(ElementType X, Stack S) {
    struct SNode* newNode = malloc(sizeof(struct SNode));
    newNode->data = X;
    newNode->next = S->next;
    S->next = newNode;
}

/* 出栈 */
ElementType pop(Stack S) {
    if (isEmpty(S)) { /* 栈空 */
        printf("the stack is empty\n");
        return NAN;
    }
    struct SNode* del = S->next; // 要删除的结点
    ElementType X = del->data;   // 取出栈顶元素
    S->next = del->next;         // 修改栈顶指针
    free(del);                   // 释放结点空间
    return X;
}