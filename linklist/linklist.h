//单向链表节点
struct onenode
{
    int value;
    onenode *next;
    /* data */
};

//双向链表节点
struct binnode
{
    int value;
    binnode *pre;
    binnode *tail;
    /* data */
};

class OneNode{
public:

    onenode *createlist_headin(onenode *head);
    onenode *createlist_tailin(onenode *head);
    void tavallist(onenode *head);
};
