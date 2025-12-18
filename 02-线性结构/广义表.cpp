using GList = struct GNode*;
using ElementType = double;
struct GNode {
    int tag; // 标志域，0表示顶点，1表示广义表
    union {  /* 子表指针域与单元素数据域共用存储空间 */
        ElementType data;
        GList sub_list;
    } URegion;
    GList next; // 指向下一个结点的指针
};