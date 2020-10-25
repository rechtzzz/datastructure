#include<iostream>
#include<vector>
using namespace std;
/*

我们把数组 A 中符合下列属性的任意连续子数组 B 称为 “山脉”：
B.length >= 3
存在 0 < i < B.length - 1 使得 B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
（注意：B 可以是 A 的任意子数组，包括整个数组 A。）
给出一个整数数组 A，返回最长 “山脉” 的长度。
如果不含有 “山脉” 则返回 0。

*/
/*void large_mount(int a[],int n){
    int right[n]  = {0};
    int left[n] = {0};

    for(int i = 0;i < n;i++){
        for(int j = i+1; j<n;j++){
            
            if(a[j-1] > a[j]){
                right[i] += 1;
            }else break;          
        }
    }
    for(int i=0;i<7;i++){
        cout<<right[i]<<"  "<<endl;
    }  
}
*/

int large_mount(int A[],int n){
    //int n = sizeof(A)/sizeof(int);
    
    vector<int >left(n);
    for(int i=1;i<n;++i){
        left[i] = (A[i-1] < A[i] ? left[i-1]+1:0);
    }

    vector<int> right(n);
    for(int i=n-2;i>=0;--i){
        right[i] = (A[i+1] < A[i]?right[i+1]+1:0);
    }

    int the_max=0;
    for(int i=0;i<n;i++){
        if(right[i]+left[i]>the_max){
            the_max = left[i]+right[i];
        }
        cout<<left[i]<<"--"<<right[i]<<endl;
    }
    return the_max+1;
}
int main(){
    int a[7] = {2,1,4,7,3,2,5};
    
    int x = large_mount(a,7);
    cout<<x;
    return 0;
}