#include<iostream>
#include<vector>
using namespace std;

vector<int > list_add(vector<int> &A,vector<int>&B){
    vector<int > ans;
    int i=0,j=0;
    while (i< A.size() || j < B.size())
    {
        if(i == A.size() || j == B.size()){
            break;
        }
        if(A[i]<B[j] ){
            ans.push_back(A[i]);
            i++;
        }else{
            ans.push_back(B[j]);
            j++;
        }
 
        
    }
    if(i == A.size()){
        for(j;j<B.size();j++){
            ans.push_back(B[j]);
        }
    }
    if(j == B.size()){
        for(i;i<A.size();i++){
            ans.push_back(A[i]);
        }
    }
    return ans;
    

}


int main(){
    vector<int> A = {1,2,4,5,6,7,7,8,9,243,456,467,866};
    vector<int> B = {2,3,9,10,23,26,34};

    vector<int> ans = list_add(A,B);
    int n = ans.size();
    float mid;
    for(int i = 0;i<n;i++){
        cout<< ans[i]<<" ";
    }
    if(n%2==0){
        mid = (ans[n/2]+ans[n/2-1])/2;
        cout<< mid;
    }else
    {
        cout<< ans[n/2];
    }
    


}
