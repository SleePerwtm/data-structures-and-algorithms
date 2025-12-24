#include "二叉树链表存储.cpp"
#include <iostream>
#include <stack>

void inOrderTraversal(BiTree BT) {
    BiTree T = BT;
    std::stack<BiTree> s;
    while (T != nullptr || !s.empty()) {
        while (T != nullptr) { /* 一直向左并把沿途结点压入堆栈 */
            s.push(T);
            T = T->left; // 切换至左子树根结点
        }
        if (!s.empty()) {
            T = s.top(); // 结点弹出堆栈
            s.pop();
            std::cout << T->data << " "; // 打印结点
            T = T->right;                // 转向右子树
        }
    }
}

void preOrderTraversal(BiTree BT) {
    BiTree T = BT;
    std::stack<BiTree> s;
    while (T != nullptr || !s.empty()) {
        while (T != nullptr) {           /* 一直向左遍历 */
            s.push(T);                   // 将当前结点压栈
            std::cout << T->data << " "; // 访问当前结点
            T = T->left;                 // 移动到左子结点
        }
        if (!s.empty()) {
            T = s.top();  // 获取栈顶结点
            s.pop();      // 弹出栈顶结点
            T = T->right; // 转向右子树
        }
    }
}

void postOrderTraversal(BiTree BT) {
    BiTree T = BT;
    BiTree lastVisited = nullptr; // 记录上一个访问的结点
    std::stack<BiTree> s;

    while (T != nullptr || !s.empty()) {
        while (T != nullptr) { /* 一直向左并将沿途结点压入堆栈 */
            s.push(T);
            T = T->left; // 切换至左子树
        }

        T = s.top(); // 查看栈顶元素，但不弹出

        /* 如果右子树为空，或者右子树已被访问 */
        if (T->right == nullptr || T->right == lastVisited) {
            s.pop();                     // 弹出栈顶元素
            std::cout << T->data << " "; // 访问根结点
            lastVisited = T;             // 更新上一个访问的结点
            T = nullptr;                 // 重置T，避免再次向左遍历
        } else {
            /* 转向右子树继续遍历 */
            T = T->right;
        }
    }
}

int main() {
    BiTree BT = exampleTree();

    std::cout << "先序遍历: ";
    preOrderTraversal(BT);
    std::cout << std::endl;

    std::cout << "中序遍历: ";
    inOrderTraversal(BT);
    std::cout << std::endl;

    std::cout << "后序遍历: ";
    postOrderTraversal(BT);
    std::cout << std::endl;

    return 0;
}