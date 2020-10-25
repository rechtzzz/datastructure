#include<iostream>
using namespace std;

/*

3
1    5
8    4    3
2    6    7    9
6    2    3    5    1  从数字他塔中获取最大路径　　　　３－５－３－９－５　　只能走正下方或者右下方

*/

int get_max(int n[][5]){
    //int row = sizeof(n)/sizeof(n[0]);
    //int line = sizeof(n[0])/sizeof(n[0][0]);
    int dq[5][5] = {0};
    dq[0][0] = n[0][0];
    for(int i = 1; i < 5 ; i++){
        for(int j = 0; j<=i;j++){
            if(j == 0){
                dq[i][j] = dq[i-1][j] + n[i][j]; 
            }else
            {
                dq[i][j] = max(dq[i-1][j],dq[i-1][j-1])+n[i][j];
            }
            
        }
    }
    int max_route = 0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(dq[i][j] > max_route){
                max_route = dq[i][j];
            }
        }
        
    }
    return max_route;
}

int main(){
    int a[5][5]={
        {3},
        {1,5},
        {8,4,3},
        {2,6,7,9},
        {6,2,3,5,1},
    };
    int max_route = get_max(a);
    cout<<max_route;
    return 0;
}