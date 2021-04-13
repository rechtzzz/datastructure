#include<iostream>
#include<stack>
#include<queue>
using namespace std;

struct treenode
{
    int data;
    treenode *right;
    treenode *left;
};

class bintree{
public:
//建立二叉树时候节点也是指针　所以要使用二级指针才能修改节点的内容
    void creat_tree(treenode * &node);
    void level_creat(treenode *&node);

    void traval_pre(treenode *root);
    void feidigui_tra(treenode *root);

    void traval_mid(treenode *root);
    void mid_feidigui(treenode *root);

    void back_feidigui(treenode *root);

    void level_tra(treenode *root);
};

//递归创建二叉树
void bintree::creat_tree(treenode *&node){
    int data = 0;
    cin>>data;
    if(data){
        node = new treenode;
        node->data = data;
        creat_tree(node->left);
        creat_tree(node->right);
    }else{
        node = NULL;
    }
}

//先序遍历递归写法
void bintree::traval_pre(treenode *node){
    
    if(node!=NULL)
    {
        cout<<node->data;
        traval_pre(node->left);
        traval_pre(node->right);
    }
}

//先序遍历非递归写法
void bintree::feidigui_tra(treenode *root){
    stack<treenode *> sta;
    treenode * pnode = root;
    //sta.push(pnode);
    while (pnode!=NULL || !sta.empty()){
        if(pnode != NULL){
            cout<<pnode->data<<",";
            sta.push(pnode);
            pnode=pnode->left;
        }else{
            pnode = sta.top();
            sta.pop();
            pnode = pnode->right;
        }
    }
}

//中序遍历递归写法 
void bintree::traval_mid(treenode *root){
    treenode *node = root;
    if(node != NULL){
        traval_mid(node->left);
        cout<<node->data<<",";
        traval_mid(node->right);
    }   
}

//中序遍历非递归写法
void bintree::mid_feidigui(treenode *root){
    stack<treenode *> nodes;
    treenode *pnode = root;

    while (pnode != NULL ||!nodes.empty()){
        if(pnode != NULL){
            nodes.push(pnode);
            pnode = pnode->left;
        }else{
            pnode = nodes.top();
            nodes.pop();
            cout<<pnode->data;
            pnode = pnode->right;
        }
    }
    
}

//后续遍历的非递归实现
void bintree::back_feidigui(treenode *root){
    stack<treenode *> nodes;
    treenode *node = root;
    //申请历史访问节点，区别同一层次内的左右节点
    treenode *lastvisit = NULL;

    while (node != NULL ||!nodes.empty())
    {
        while (node != NULL)//先深度遍历到左子树最底部
        {
            nodes.push(node);
            node = node->left;
        }
        // 获取栈顶元素
        if(!nodes.empty()){
            node = nodes.top();
            nodes.pop();
        }

        //如果节点的右子数为空，直接打印节点数据，否则就将右节点压入站内
        if(node->right == NULL || node->right == lastvisit){
            cout<<node->data<<" ,";
            lastvisit = node;
            node = NULL;
            //node = nodes.top();
            //nodes.pop();
        }else{
            nodes.push(node);
            node = node->right;
        }   
    }
}
//层次遍历
void bintree::level_tra(treenode *root){
    queue<treenode *> que;
    treenode *node = root;
    que.push(node);
    while (!que.empty()){
        node = que.front();
        que.pop();
        cout<<node->data;
        if(node->left != NULL){
            que.push(node->left);
        }
        if(node->right != NULL){
            que.push( node->right);
        }
    }
    
}

int main(){
    treenode *root;
    bintree bt;
    bt.creat_tree(root);
    //bt.traval_pre(root);
    cout<<endl;
    //bt.feidigui_tra(root);
    //bt.traval_mid(root);
    //bt.mid_feidigui(root);
    //bt.back_feidigui(root);
    bt.level_tra(root);
    return 0;
}
