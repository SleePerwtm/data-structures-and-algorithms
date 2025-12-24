#include <iostream>

using ElementType = char;
using BiTree = struct TreeNode*;

struct TreeNode {
    ElementType data;
    BiTree left;
    BiTree right;
};

BiTree exampleTree() {
    BiTree root = new TreeNode{'A'};
    root->left = new TreeNode{'B'};
    root->right = new TreeNode{'C'};
    root->left->left = new TreeNode{'D'};
    root->left->right = new TreeNode{'F'};
    root->right->left = new TreeNode{'G'};
    root->right->right = new TreeNode{'I'};
    root->left->right->left = new TreeNode{'E'};
    root->right->left->right = new TreeNode{'H'};
    return root;
}