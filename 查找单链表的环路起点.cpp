#include<iostream>
using namespace std;
    
#include "linklist/linklist.h"
/*单链表找环起点
如果存在环路 必然会在进入环路之后一直运行
声明快慢指针  如果存在环路  如果存在环路 必然会相遇
*/
onenode *createlist_tailin(onenode *head){
    if(head == nullptr)
        return NULL;
    onenode *pnode=nullptr,*temp=nullptr;
    pnode = head;
    int value=0;
    std::cin >>value;
    while(value){
        temp=new onenode();
        temp->value=value;
        pnode->next=temp;
        pnode = temp;
        std::cin>>value;
    }
    return head;
}

onenode * check_cir(onenode *head){
    onenode *step1= head,*step2= head;

    while (step1 != nullptr &&step2 != nullptr){
        step1 = step1->next;
        step2 = step2->next->next;

        if(step1 == step2){
            return step1;
        }
    }
    return nullptr; 
}

//链表成环
bool makecir(onenode *head,int value){
    //在链表value处为环的起点
    if(head == nullptr )
        return false;
    onenode *temp=head->next,*lstart=nullptr;
    bool findit=false;
    while (temp->next!=nullptr)
    {
        if( !findit && temp->value==value ){
            lstart=temp;
            findit=true;
        }

        temp = temp->next;
        /* code */
    }
    if(findit){
        temp->next = lstart;
        return true;
    }else{
        return false;
    }
    
}
int main(){
    onenode *head,*res_start=nullptr;

    

    head = createlist_tailin(head);

    if(makecir(head,5)){//人为造环 尾结点连接到value值为5的节点上
        cout<< "造环成功"<<endl;
    }else{
        cout<<"造环失败 ，未找到该节点"<<endl;
    }

    if(res_start = check_cir(head)){
        cout<<"起点为："<<res_start->value;
    }else{
        cout<<"没有坏"<<endl;
    }

    

    return 0;
    
}