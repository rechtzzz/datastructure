#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>

#include "bintree.h"

using namespace std;

BTree::BTree(){}

    //传参需要注意，二叉树是指针类型的，节点本身就是一个指针：*node。所以需要二级指针才能改变二叉树的内容
void BTree::createtree(BTreeNode* &Node){
    int data;
    cin >> data;
    if(data){
        Node = new BTreeNode;
        Node->data = data;
        //cout<<"data:"<<data<<endl;
        createtree(Node->left);
        createtree(Node->right);
    } else{
        Node=NULL;
        
    }
}
//按层创建二叉树
void BTree::levelCreate(BTreeNode* &Node){
    queue <BTreeNode*> que;
    int data;
    cin>>data;
    if(data){
        Node = new BTreeNode;
        Node->data = data;
        que.push(Node);
    } else{
        Node = NULL;
        return;
    }
    while(!que.empty()){
        BTreeNode *node = que.front();
        que.pop();
        //输入左边数据
        cin>>data;
        if(data){
            node->left = new BTreeNode;
            node->left->data = data;
            que.push(node->left);
        } else{
            node->left = NULL;
        }
        //输入右边数据
        cin >>data;
        if(data){
            node->right = new BTreeNode;
            node->right->data = data;
            que.push(node->right);
        } else{
            node->right = NULL;
        }
    }
}

//清除二叉树
void BTree::clear(BTreeNode*& Node){
    BTreeNode *p = Node;
    if(p != NULL){
        clear(Node->left);
        clear(Node->right);
        delete p;
    }
}
//前序遍历(根左右)
void BTree::preorderTree(BTreeNode* Node){
    if(Node!=NULL){
        cout<<Node->data<<" ,";
        preorderTree(Node->left);
        preorderTree(Node->right);
    }
}
//前序遍历非递归写法
void BTree::NnredursionPreorder(BTreeNode* Node){
    stack<BTreeNode*> node;
    node.push(Node);
    BTreeNode *pNode = Node;
    while(pNode != NULL || !node.empty()){
        //1、先把节点打印，并且入栈，将节点的左孩子作为当前的节点
        //2、当节点不为空或者栈不为空，就取出栈顶，
        if(pNode != NULL){

            cout<<pNode->data<<" ";
            node.push(pNode);
            pNode = pNode->left;
        } else{
            pNode = node.top();
            node.pop();
            pNode = pNode->right;

        }
    }
}

//中序遍历(左中右)
void BTree::inorderTree(BTreeNode* Node){
    if(Node != NULL){
        inorderTree(Node->left);
        cout<<Node->data<<" ,";
        inorderTree(Node->right);
    }
}

//后序遍历（左右中）
void BTree::postorderTree(BTreeNode* Node){
    if(Node != NULL){
        postorderTree(Node->left);
        postorderTree(Node->right);
        cout<<Node->data<<" ,";
    }
}
//层序遍历
void BTree::levelTree(BTreeNode *Node){
    queue<BTreeNode*> que;
    if(Node == NULL) return;
    else{
        que.push(Node);
        while(!que.empty()){
            BTreeNode *node = que.front();
            cout<<node->data<<" ";
            que.pop();
            if(node->left != NULL){
                que.push(node->left);
            }
            if(node->right!=NULL){
                que.push(node->right);
            }
        }
    }
}
//二叉树深度
int BTree::depthOfTree(BTreeNode* Node){
    if(Node){
        return max(depthOfTree(Node->left),depthOfTree(Node->right))+1;
    } else{
        return 0;
    }
}
//返回节点总数目
int BTree::getNodeNum(BTreeNode* Node){
    if(Node){
        return 1+getNodeNum(Node->left)+getNodeNum(Node->right);
    } else{
        return 0;
    }
}
//返回叶子节点个数
int BTree::getLeafNum(BTreeNode* Node){
    if(!Node){
        return 0;
    } else if(Node->left == NULL && Node->right == NULL){
        return 1;
    } else{
        return getLeafNum(Node->left)+getLeafNum(Node->right);
    }
}

int main(){
    BTree tree;
    BTreeNode *root;
    tree.createtree(root);
    //tree.levelCreate(root);
    tree.NnredursionPreorder(root);
    /*
    cout<<"pre :";
    //tree.preorderTree(root);
    cout<<endl;
    cout<<"in  :";
    tree.inorderTree(root);
    cout<<endl;
    cout<<"post:";
    tree.postorderTree(root);
    cout<<endl;
    cout<<"level:";
    tree.levelTree(root);
    cout<<endl;
    cout<<"NodeNum:"<<tree.getNodeNum(root)<<",depth:"<<tree.depthOfTree(root)<<",leaf:"<<tree.getLeafNum(root)<<endl;

*/
    cout<<tree.getLeafNum(root);
    tree.clear(root);
    return 0;
}