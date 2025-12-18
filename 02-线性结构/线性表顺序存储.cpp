#include <iostream>
#include <cmath>

using ElementType = double;
using Index = int;

const int kMaxSize = (int)1e4; // 线性表最大长度

struct LNode {
    ElementType data[kMaxSize]; // 储存的数据
    int last;                   // 最后一个元素的下标
};

using List = LNode*;

/* 初始化一个空线性表 */
List makeEmpty() {
    List ptrL;
    ptrL = new LNode;
    ptrL->last = -1;
    return ptrL;
}

/* 根据索引 K 返回相应元素 */
ElementType findKth(Index K, List ptrL) {
    if (K < 0 || K > ptrL->last) {
        std::cout << "The position is invalid\n";
        return NAN; /* 对于 double 类型，返回 NaN 表示错误 */
    }
    return ptrL->data[K];
}

/* 在线性表中查找 X 第一次出现的位置索引 */
Index find(ElementType X, List ptrL) {
    int i = 0;
    while (i <= ptrL->last && ptrL->data[i] != X)
        i++;
    if (i > ptrL->last)
        return -1; // 没找到返回 -1
    return i;      // 找到了返回位置索引
}

/* 在下标 i 处插入 X 元素 */
bool insertByIndex(ElementType X, Index i, List ptrL) {
    if (ptrL->last == kMaxSize - 1) { /* 表空间已满 */
        std::cout << "The list is full\n";
        return false;
    }
    if (i < 0 || i > ptrL->last + 1) { /* 插入位置不合法 */
        std::cout << "The position is invalid\n";
        return false;
    }
    for (int j = ptrL->last; j >= i; --j) {
        ptrL->data[j + 1] = ptrL->data[j]; // a_i 到 a_n 向后移动一位
    }
    ptrL->data[i] = X; // 插入新元素
    ++ptrL->last;      // last 指向最后一个元素
    return true;
}

/* 删除指定下标 i 的元素 */
bool deleteByIndex(Index i, List ptrL) {
    if (i < 0 || i > ptrL->last) { /* 删除位置不合法 */
        std::cout << "The position is invalid\n";
        return false;
    }
    for (int j = i; j < ptrL->last; ++j) {
        ptrL->data[j] = ptrL->data[j + 1]; // a_{i+1} 到 a_n 向前移动一位
    }
    --ptrL->last; // last 指向最后一个元素
                  // 当删除数组最后一个元素之后，last=-1，代表为空表
    return true;
}

/* 返回线性表的长度 n */
int length(List ptrL) { return ptrL->last + 1; }