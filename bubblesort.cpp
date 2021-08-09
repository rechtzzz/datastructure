#include<iostream>
using namespace std;

void swap(int *x,int *y){
    int *p=x;
    *x = *y;
    *y = *p;
}
void bubbles(int *a,int len ){
    for (size_t i = 0; i < len-1; i++)
    {
        /* code */
        for (size_t j = 0; j < len-1-i; j++)
        {
            /* code */
            if(*(a+j)>*(a+j+1)){
                swap(*(a+j),*(a+j+1));
            }
        }
    }
}
int main(){
    int a[]={5,3,9,6,12,55,78,3,0,8,6,1,0,845,0,2,5,7,1,5};
    int len=sizeof(a)/sizeof(int);
    bubbles(a,len);
    for(int i=0;i<len;i++){
        cout<<*(a+i)<<" ";
    }
    return 0;
}