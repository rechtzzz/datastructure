#include<iostream>
#include<stack>
#include<queue>
using namespace std;


/*
 使用两个栈实现队列的简单操作
*/
class squeue{
public:
    void front();
    void push(const int value);
    int pop();

private:
    int curr_size=0;
    const int maxsize = 10;
    stack<int> sin;
    stack<int> sout;
};

void squeue::front(){
    if(sout.empty()){
        if(!sin.empty()){
            while(!sin.empty()){
                sout.push(sin.top());
                sin.pop();
            }
            cout<<sout.top();
            sout.pop();
            curr_size -=1;
        }else{
            cout<<"queue is empty"<<endl;
        }
    }else{
        cout<<sout.top();
        sout.pop();
        curr_size -=1;
    }
}

void squeue::push(const int value){
    if(curr_size<maxsize){
        sin.push(value);
        curr_size += 1;
    }else{
        cout<<"queue is full"<<endl;
    }
}

int main(){
    squeue s1;
    s1.push(1);
    s1.push(2);
    s1.front();
    s1.push(3);
    s1.push(4);
    s1.push(5);
        s1.push(3);
    s1.push(4);
    s1.push(5);
        s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.front();
    s1.push(4);
    s1.push(5);
        s1.push(3);
    s1.push(4);
    s1.front();
    s1.front();
    s1.front();
    s1.front();
    s1.push(5);
}