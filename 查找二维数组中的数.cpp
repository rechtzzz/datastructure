#include<iostream>
using namespace std;
#include<vector>
/*
编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：
每行的元素从左到右升序排列。
每列的元素从上到下升序排列。
*/

/*
从数组的右上角为搜索起点，判断与target的大小，
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int j=n-1,i=0;
        while(i<m&&j>=0){
            if(target==matrix[i][j]){
                return true;
            }else if(target<matrix[i][j]){
                j--;
            }else if(target>matrix[i][j]){
                i++;
            }    
        }
        return false;
    }
};
int main(){
    vector<vector<int>> mu({{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24}});
    cout<<mu.size();
    cout<<mu[0].size()<<endl;
    Solution *sol =  new Solution();
    

    if(sol->searchMatrix(mu,5)){
        cout<<"1"<<endl;
    }else cout<<"0"<<endl;
    return 0;
}