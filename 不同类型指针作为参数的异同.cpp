#include<iostream>
#include<cstring>
using namespace std;

//一级指针 形参不能影响实参
void func1(char *p){
    p = (char*)malloc(100);
}
//正常形参不能影响实参，如果函数对于指针指向的数据更改则会导致原来数据变化。
//二级指针 参数为原指针地址的指针 故函数操作直接影响原指针内容  一下结果运行正常
void func2(char **p){
    *p = (char*)malloc(100);
}

char * func3(void){
    char p[]="hello world";
    return p;
}
int main(){
    //不能输出结果，func1并未成功申请空间
    /*char *p1=nullptr;
    func1(p1);
    strcpy(p1,"hello");
    cout<<p1;  */


    char *p2=nullptr;
    func2(&p2);
    strcpy(p2,"hello");
    cout<<"p2:"<<p2<<endl;


   /* char *p3=nullptr;
    p3 = func3();    //address of local variable 'p' returned  函数内定义变量  函数结束自动释放
    cout<<p3<<endl;
    cout<<p3;*/
    return 0;
    
}