#include<iostream>
using namespace std;

/*
T0 = 0, T1 = 1, T2 = 1, 且在 n >= 0 的条件下 Tn+3 = Tn + Tn+1 + Tn+2

给你整数 n，请返回第 n 个泰波那契数 Tn 的值。
*/

int tbnq_r(int n){
    if(n<0)
        return -1;
    else if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else if(n==2)
        return 1;
    else 
         return tbnq_r(n-3)+tbnq_r(n-2)+tbnq_r(n-1);
}
int tbnqnr(int n){
    int t0=0,t1=1,t2=1,res=0,index=3;
    if(n==0)
        return t0;
    if(n==1)
        return t1;
    if(n==2)
        return t2;
    while(index<=n){
        res = t0+t1+t2;
        t0=t1;
        t1=t2;
        t2=res;
        index++;
    }
    return res;
}
int main(){
    cout<<tbnq_r(25)<<endl;
    cout<<tbnqnr(25);
    return 0;
}