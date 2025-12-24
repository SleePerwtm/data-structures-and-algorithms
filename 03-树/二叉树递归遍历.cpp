#include "二叉树链表存储.cpp"
#include <iostream>

/* 先序遍历 */
void preOrderTraversal(BiTree BT) {
    if (BT != nullptr) {
        std::cout << BT->data << " "; // 访问根结点
        preOrderTraversal(BT->left);  // 遍历左子树
        preOrderTraversal(BT->right); // 遍历右子树
    }
}

/* 中序遍历 */
void inOrderTraversal(BiTree BT) {
    if (BT != nullptr) {
        inOrderTraversal(BT->left);   // 遍历左子树
        std::cout << BT->data << " "; // 访问根结点
        inOrderTraversal(BT->right);  // 遍历右子树
    }
}

/* 后序遍历 */
void postOrderTraversal(BiTree BT) {
    if (BT != nullptr) {
        postOrderTraversal(BT->left);  // 遍历左子树
        postOrderTraversal(BT->right); // 遍历右子树
        std::cout << BT->data << " ";  // 访问根结点
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