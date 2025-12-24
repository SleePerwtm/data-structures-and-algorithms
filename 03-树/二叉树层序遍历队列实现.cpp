#include "二叉树链表存储.cpp"
#include <iostream>
#include <queue>
#include <stack>

void levelOrderTraversal(BiTree BT) {
    if (BT == nullptr) /* 如果树为空，直接返回 */
        return;
    BiTree T = BT;
    std::queue<BiTree> q;
    q.push(T);                       // 将根结点入队
    while (!q.empty()) {             /* 队列不为空时继续遍历 */
        T = q.front();               // 获取队首结点
        q.pop();                     // 队首结点出队
        std::cout << T->data << " "; // 访问当前结点
        if (T->left != nullptr)
            q.push(T->left); // 左子结点入队
        if (T->right != nullptr)
            q.push(T->right); // 右子结点入队
    }
}

/* 直接把队列换成栈 */
void traversal(BiTree BT) {
    if (BT == nullptr) /* 如果树为空，直接返回 */
        return;
    BiTree T = BT;
    std::stack<BiTree> q;
    q.push(T);                       // 将根结点入队
    while (!q.empty()) {             /* 队列不为空时继续遍历 */
        T = q.top();                 // 获取队首结点
        q.pop();                     // 队首结点出队
        std::cout << T->data << " "; // 访问当前结点
        if (T->left != nullptr)
            q.push(T->left); // 左子结点入队
        if (T->right != nullptr)
            q.push(T->right); // 右子结点入队
    }
}

int main() {
    BiTree BT = exampleTree();

    std::cout << "层序遍历: ";
    levelOrderTraversal(BT);
    std::cout << std::endl;

    std::cout << "遍历: ";
    traversal(BT);
    std::cout << std::endl;

    return 0;
}