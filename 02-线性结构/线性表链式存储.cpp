#include <iostream>

using ElementType = double; // 线性表中元素的数据类型
using List = struct LNode*; // 线性表类型定义

struct LNode {
    ElementType data; // 该节点的数据
    List next;        // 指向下一个元素的指针
};

/* 初始化一个空线性表 */
List makeEmpty() { return nullptr; }

/* 根据下标 K 返回相应元素 */
List findKth(int K, List ptrL) {
    List p = ptrL;
    int i = 0;
    while (p != nullptr && i < K) {
        p = p->next;
        ++i;
    }
    if (i == K)
        return p; /*  找到第K个元素，返回指针 */
    else
        return nullptr; /* 未找到，返回 nullptr */
    // 其实直接 return p; 也是等价的，不过可读性相对较差
}

/* 在线性表中查找 X 第一次出现的结点 */
List find(ElementType X, List ptrL) {
    List p = ptrL;
    while (p != nullptr && p->data != X) {
        p = p->next;
    }
    return p; /* 找到返回指针，未找到返回nullptr */
}

/* 在下标 i 的元素处插入 X 元素 */
List insert(ElementType X, int i, List ptrL) {
    List p, newNode;
    if (i == 0) {            /* 新节点插入在表头 */
        newNode = new LNode; // 为新结点分配内存
        newNode->data = X;
        newNode->next = ptrL;
        return newNode; // 返回新的表头指针
    }
    p = findKth(i - 1, ptrL); // 找到第 i-1 个元素
    if (p == nullptr) {       /* 第 i-1 个元素不存在 */
        std::cout << "the " << i << " is incorrect!\n";
        return ptrL; // 返回原表头指针
    } else {
        newNode = new LNode; // 为新结点分配内存
        newNode->data = X;
        newNode->next = p->next;
        p->next = newNode; // 新节点插入在 p 之后
        return ptrL;       // 返回原表头指针
    }
}

/* 删除指定下标 i 的元素 */
List deleteByIndex(int i, List ptrL) {
    List p, del;
    if (i == 0) { /* 需要删除的是表头节点 */
        del = ptrL;
        ptrL = ptrL->next; // 删除表头节点
        delete del;
        return ptrL; // 返回新的表头指针
    }
    p = findKth(i - 1, ptrL);                 // 找到第 i-1 个元素
    if (p == nullptr || p->next == nullptr) { /* 第 i-1 或第 i 个元素不存在 */
        std::cout << "the " << i << " is incorrect!\n";
        return nullptr; // 返回空指针表示删除失败
    } else {
        del = p->next;       // 需要删除的节点
        p->next = del->next; // 删除第 i 个节点
        delete del;          // 释放被删除节点的内存
        return ptrL;
    }
}

/* 返回线性表的长度 n */
int length(List ptrL) {
    int i = 0;
    List p = ptrL;
    while (p != nullptr) {
        ++i;
        p = p->next;
    }
    return i;
}