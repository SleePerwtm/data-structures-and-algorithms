#include <math.h>
#include <stdio.h>

#define MAXSIZE (int)1e4

typedef struct SNode* Stack;
typedef double ElementType;

#define bool _Bool
#define true 1
#define false 0

struct SNode {
    ElementType data[MAXSIZE]; // 储存的数据
    int top;                   // 栈顶指针
};

/* 判断栈是否为空 */
bool isEmpty(Stack S) { return S->top == -1; }

/* 判断栈是否为满 */
bool isFull(Stack S) { return S->top == MAXSIZE - 1; }

/* 入栈 */
bool push(ElementType X, Stack S) {
    if (isFull(S)) { /* 栈满 */
        printf("the stack is full\n");
        return false;
    }
    S->data[++S->top] = X; // 入栈
    return true;
}

/* 出栈 */
ElementType pop(Stack S) {
    if (isEmpty(S)) { /* 栈空 */
        printf("the stack is empty\n");
        return NAN;
    }
    ElementType X = S->data[S->top--]; // 出栈
    return X;
}