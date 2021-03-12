#include<iostream>
using namespace std;
/*
    简单实现队列
*/
template<typename T>
struct node
{   
    T data;
    node *next;
};

template<typename T>
class testqueue{
public:
    testqueue(){
        this->head = new node<T>();
        this->head->next = nullptr;
    }
    testqueue(T data){
        this->head = new node<T>();
        node<T> *pnode = new node<T>();
        pnode->data = data;
        pnode->next = nullptr;
        this->head->next = pnode;
    }
    ~testqueue(){
        free(this->head);
    }
    void front();
    void pop();
    void traval();
    void push(T data);

private:
    node<T> *head;

};

template<typename T>
void testqueue<T>::front(){
    if(this->head->next != nullptr){
        cout<<this->head->next->data<<endl;
    }
    return;
}

template<typename T>
void testqueue<T>::pop(){
    if(this->head->next != nullptr){
        node<T> *temp = this->head;
        this->head = this->head->next;
        cout<<"pop:"<<temp->next->data<<endl;
        free(temp);
    }
    return;
}

template<typename T>
void testqueue<T>::push(T data){
    node<T> *temp = this->head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    node<T> *pnode = new node<T>();
    pnode->data = data;
    pnode->next = nullptr;
    temp->next = pnode;
}

template<typename T>
void testqueue<T>::traval(){
    node<T> *temp = this->head->next;
    while (temp != nullptr)
    {
        cout<<temp->data<<endl;
        temp = temp->next;
    }
    return;
}

int main(){
    testqueue<int> tq;

    tq.push(1);
    tq.push(2);
    tq.push(3);
    tq.push(4);
    tq.pop();
    tq.front();
    tq.push(5);
    tq.traval();
    return 0;
}