struct BTreeNode{
    int data = 0;
    BTreeNode *left;
    BTreeNode *right;
};


class BTree{
public:
    BTree();
    //传参需要注意，二叉树是指针类型的，节点本身就是一个指针：*node。所以需要二级指针才能改变二叉树的内容
    void createtree(BTreeNode* &Node);

    //按层创建二叉树
    void levelCreate(BTreeNode* &Node);

    //清除二叉树
    void clear(BTreeNode*& Node);

    //前序遍历(根左右)
    void preorderTree(BTreeNode* Node);

    //前序遍历非递归写法
    void NnredursionPreorder(BTreeNode* Node);

    //中序遍历(左中右)
    void inorderTree(BTreeNode* Node);

    //后序遍历（左右中）
    void postorderTree(BTreeNode* Node);

    //层序遍历
    void levelTree(BTreeNode *Node);

    //二叉树深度
    int depthOfTree(BTreeNode* Node);

    //返回节点总数目
    int getNodeNum(BTreeNode* Node);

    //返回叶子节点
    int getLeafNum(BTreeNode* Node);



};