#include<iostream>
#include<vector>
using namespace std;

//动态规划算法
/*
    同第i位表示在该位上子序列最大的数   如果第i位得数加上i-1位的数变小 说明在i位上从i开始算作最大子序列的开始  所以开始遍历i+1 的值
    dp[i] = max(d[i],d[i-1]+d[i])
*/
int max(int a,int b){
    return a>b?a:b;
}
void maxsublist(vector<int> &nums){
    int res=nums[0];
    for(int i=1;i<nums.size();i++){
        nums[i] = max(nums[i],nums[i]+nums[i-1]);
        res = max(nums[i],res);
        
    }
    cout<<res<<endl;;
}
int main(){
    vector<int> a={-2,1,-3,4,-1,2,1,-5,4};   //结果是6
    maxsublist(a);
    for(auto i:a){
        cout<<i<< " "; 
    }
    return 0;
}