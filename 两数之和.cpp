#include<iostream>
#include<map>
#include<vector>
using namespace std;

/*
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
你可以按任意顺序返回答案。

输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
int *findit(vector<int> &nums,int target){
    int *res = (int *)malloc(2);
    if(nums.size()<3)
        return nullptr;
    map<int,int> ms;
    map<int,int>::iterator iter;
    ms.insert(pair<int,int>(nums[0],0));
    for(int i=1;i<nums.size();i++){
        int aim = target-nums[i];
        iter = ms.find(aim);
        if(iter == ms.end()){
            ms.insert(pair<int,int>(nums[i],i));
        }else{
            res[0]=i;
            res[1]=ms[aim];
            return res;
        }
    }
    return nullptr;
}

int main(){
    vector<int>nums = {2,4,6,8,2,7,0,7,123,43,23,4,3,66,7,11,15};
    int *res=nullptr;
    if(res = findit(nums,17)){
        cout<<*res<<"-"<<*(res+1)<<endl;
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }
    return 0;
}