#include <stdio.h>
#include <stdlib.h>

// 二叉树结点类型
typedef struct BiTreeNode {
    char data;
    struct BiTreeNode *left, *right;
} BiTreeNode, *BiTree; // 定义了二叉树结点类型、指向根节点指针类型

// 前序遍历创建二叉树
void PreOrderCreateBiTree(BiTree* T) {
    char data;
    scanf("%c", &data);
    if (data == '#') {
        *T = NULL;
        return;
    } else {
        *T = (BiTreeNode*)malloc(sizeof(BiTreeNode));
        (*T)->data = data;
        PreOrderCreateBiTree(&(*T)->left);
        PreOrderCreateBiTree(&(*T)->right);
    }
}

void visit(BiTree T, int level) {
    printf("结点%c位于第%d层\n", T->data, level);
}

void PreOrderBiTree(BiTree T, int level) {
    if (T != NULL) {
        visit(T, level);
        PreOrderBiTree(T->left, level + 1);
        PreOrderBiTree(T->right, level + 1);
    }
}

void FreeBiTree(BiTree T) {
    if (T == NULL) {
        return;
    }
    FreeBiTree(T->left);
    FreeBiTree(T->right);
    free(T);
}

int main() {
    int level = 1;
    BiTree T = NULL;
    PreOrderCreateBiTree(&T);
    PreOrderBiTree(T, level);
    FreeBiTree(T);

    return 0;
}