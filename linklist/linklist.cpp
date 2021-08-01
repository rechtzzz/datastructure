#include<iostream>

#include "linklist.h"

//头插法
onenode *OneNode::createlist_headin(onenode *head){
    if(head == nullptr)
        return NULL;
    onenode *pnode=nullptr,*temp=nullptr;
    pnode = head;
    int value=0;
    std::cin >>value;
    while(value){
        temp=new onenode();
        temp->value=value;
        temp->next=nullptr;

        temp->next = pnode->next;
        pnode->next = temp;

        std::cin>>value;
    }
    return head;
}


//尾插法
onenode *OneNode::createlist_tailin(onenode *head){
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

void OneNode::tavallist(onenode *head){
    if(head == nullptr)
        return;
    onenode *temp=head->next;
    while (temp != nullptr){
        std::cout<<temp->value<<" ";
        temp = temp->next;
    }
    
}

/*int main(){
    onenode *head;
    OneNode *testlist = new OneNode();
    head = testlist->createlist_headin(head);
    testlist->tavallist(head);
    return 0;
}*/