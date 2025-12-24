#include <iostream>
#include <vector>

template <typename T> inline T max(T a, T b) { return a > b ? a : b; }

template <class ElementType> class AVLTree {
  private:
    struct AVLNode {
        ElementType data;
        AVLNode* left;
        AVLNode* right;
        int height;
    };

    AVLNode* root = nullptr;

    inline int balanceFactor(AVLNode* node) {
        return height(node->left) - height(node->right);
    }

    /*
     * 获取节点高度的辅助函数
     * 为了防止访问空指针异常，传入空指针时高度定义为-1
     */
    inline int height(AVLNode* node) { return node ? node->height : -1; }

    /* 实现单右旋 */
    AVLNode* rotationR(AVLNode* A) {
        AVLNode* B = A->left;
        /* 修改指针实现右旋 */
        A->left = B->right;
        B->right = A;
        /* 更新A、B高度 */
        A->height = max(height(A->left), height(A->right)) + 1;
        B->height = max(height(B->left), A->height) + 1;
        /* B为旋转后该结构的根节点，将其返回 */
        return B;
    }

    /* 实现单左旋 */
    AVLNode* rotationL(AVLNode* A) {
        AVLNode* B = A->right;
        /* 修改指针实现左旋 */
        A->right = B->left;
        B->left = A;
        /* 更新A、B高度 */
        A->height = max(height(A->left), height(A->right)) + 1;
        B->height = max(A->height, height(B->right)) + 1;
        /* B为旋转后该结构的根节点，将其返回 */
        return B;
    }

    /* 先左旋后右旋 */
    AVLNode* rotationLR(AVLNode* A) {
        /* 中间节点进行左旋 */
        A->left = rotationL(A->left);
        /* 根节点进行右旋，返回新的根节点 */
        return rotationR(A);
    }

    /* 先右旋后左旋 */
    AVLNode* rotationRL(AVLNode* A) {
        /* 中间节点进行右旋 */
        A->right = rotationR(A->right);
        /* 根节点进行右旋，返回新的根节点 */
        return rotationL(A);
    }

    /* AVL树的插入操作 */
    AVLNode* insert(ElementType X, AVLNode* T) {
        if (T == nullptr) { /* 传入结点为空，创建新结点 */
            T = new AVLNode{X, nullptr, nullptr, 0};
            return T;
        } else if (X < T->data) { /* 插入左子树 */
            T->left = insert(X, T->left);
            if (balanceFactor(T) == 2) {
                if (X < T->left->data) { /* LL型 */
                    T = rotationR(T);    // 单右旋
                } else {                 /* LR型 */
                    T = rotationLR(T);   // 先左旋后右旋
                }
            }
        } else if (X > T->data) { /* 插入右子树 */
            T->right = insert(X, T->right);
            if (balanceFactor(T) == -2) {
                if (X > T->right->data) { /* RR型 */
                    T = rotationL(T);     // 单左旋
                } else {                  /* RL型 */
                    T = rotationRL(T);    // 先右旋后左旋
                }
            }
        }

        /* 更新节点高度 */
        T->height = max(height(T->left), height(T->right)) +
                    1; // 是必要的，因为没有发生的插入不会更新高度
                       // 因此必须在这里进行一次更新
        return T;
    }

    void displayTreeLikeATree(AVLNode* T, int depth) {
        if (T == nullptr)
            return;
        displayTreeLikeATree(T->right, depth + 1);
        for (int i = 0; i < depth; i++)
            std::cout << "    ";
        std::cout << T->data << std::endl;
        displayTreeLikeATree(T->left, depth + 1);
    }

  public:
    // 构造函数
    AVLTree() : root(nullptr) {}

    // 析构函数
    ~AVLTree() { destroyTree(root); }

    // 插入接口
    void insert(ElementType value) { root = insert(value, root); }

    // 显示接口
    void display() { displayTreeLikeATree(root, 0); }

  private:
    // 销毁树的辅助递归函数
    void destroyTree(AVLNode* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }
};

template <typename ElementType>
void insertVec(std::vector<ElementType> vec, AVLTree<ElementType>& avl) {
    for (const auto& item : vec) {
        avl.insert(item);
    }
}

int main() {
    AVLTree<int> avl;
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    insertVec(vec, avl);
    avl.display();
    return 0;
}