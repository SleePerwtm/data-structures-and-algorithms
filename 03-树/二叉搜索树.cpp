#include<iostream>

using ElementType = char;
using BiTree = struct TreeNode*;

struct TreeNode {
    ElementType data;
    BiTree left;
    BiTree right;
};

BiTree find(ElementType X, BiTree BST) {
    if (BST == nullptr) /* 查找失败 */
        return nullptr;
    if (X < BST->data) { /* 小于根节点，在左子树中查找 */
        return find(X, BST->left);
    } else if (X > BST->data) { /* 大于根节点，在右子树中查找 */
        return find(X, BST->right);
    } else { /* 等于根节点，查找成功，返回结点指针 */
        return BST;
    }
}

BiTree iterarionFind(ElementType X, BiTree BST) {
    while (BST != nullptr) {
        if (X < BST->data) {
            BST = BST->left; // 向左子树移动，继续查找
        } else if (X > BST->data) {
            BST = BST->right; // 向右子树移动，继续查找
        } else {
            return BST;
        }
    }
    return nullptr; // 查找失败
}

/* 递归查找二叉排序树中的最小元素结点 */
BiTree findMin(BiTree BST) {
    if (BST == nullptr) { /* 空二叉树，返回空指针 */
        return nullptr;
    } else if (BST->left == nullptr) { /* 找到最小元素 */
        return BST;
    } else { /* 继续在左子树中查找最小元素 */
        return findMin(BST->left);
    }
}

/* 迭代查找二叉排序树中的最大元素结点 */
BiTree findMax(BiTree BST) {
    if (BST == nullptr) { /* 空二叉树，返回空指针 */
        return nullptr;
    }
    while (BST->right != nullptr) { /* 不断向右子树移动，直到找到最大元素 */
        BST = BST->right;
    }
    return BST;
}

/* 递归插入 */
BiTree insert(ElementType X, BiTree BST) {
    if (BST == nullptr) { /* 树为空，创建新结点 */
        BST = new TreeNode{X, nullptr, nullptr};
    } else if (X < BST->data) { /* 值小于根节点，插入左子树 */
        BST->left = insert(X, BST->left);
    } else if (X > BST->data) { /* 值大于根节点，插入右子树 */
        BST->right = insert(X, BST->right);
    }
    return BST;
}

/* 迭代插入 */
BiTree iterationInsert(ElementType X, BiTree BST) {
    BiTree T = BST;
    if (BST == nullptr) { /* 树为空，创建新结点 */
        BST = new TreeNode{X, nullptr, nullptr};
        return BST;
    }
    while (BST != nullptr) {
        if (X < BST->data) {
            if (BST->left == nullptr) { /* 找到插入位置 */
                BST->left = new TreeNode{X, nullptr, nullptr};
                return T;
            }
            BST = BST->left; // 向左子树移动，继续查找插入位置
        } else if (X > BST->data) {
            if (BST->right == nullptr) { /* 找到插入位置 */
                BST->right = new TreeNode{X, nullptr, nullptr};
                return T;
            }
            BST = BST->right; // 向右子树移动，继续查找插入位置
        } else {
            return T; // 元素已存在，不插入
        }
    }
    return T;
}

/* 删除结点 */
BiTree deleteNode(ElementType X, BiTree BST) {
    if (BST == nullptr) { /* 树为空，未找到要删除的元素，返回空指针 */
        return nullptr;
    }
    if (X < BST->data) {
        BST->left = deleteNode(X, BST->left); /* 在左子树中删除 */
    } else if (X > BST->data) {
        BST->right = deleteNode(X, BST->right); /* 在右子树中删除 */
    } else {
        BiTree temp;
        if (BST->left != nullptr && BST->right != nullptr) {
            temp = findMin(BST->right);
            BST->data = temp->data;
            BST->right = deleteNode(temp->data, BST->right);
        } else {
            temp = BST;
            /*
             * 三种情况：无子结点、只有有孩子、只有左孩子
             * 无子结点时，BST 要赋值为 nullptr，之后返回
             */
            if (BST->right == nullptr) { /* 有左孩子或无子结点 */
                BST = BST->left;
            }
            if (BST->left == nullptr) { /* 有右孩子或无子结点 */
                BST = BST->right;
            }
            delete temp;
        }
    }
    return BST;
}