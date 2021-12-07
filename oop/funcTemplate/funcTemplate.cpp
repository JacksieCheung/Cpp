// p8_1
#include<iostream>

using namespace std;

template<class T1, class T2>
T1 add(T1 x, T2 y){ // 中间可以有空格，但是必须
    cout<<"("<<sizeof(T1)<<","<<sizeof(T2)<<")"<<endl;
    return x + y;
}

template<class T1,class T2,int size> // 如果模板有一般类型，不能隐式实例化
void NumDelete(T1 x,T2 y){ // 一般类型在形参里面不使用
    cout<<(x-y)*size<<endl;
}

int main(){
    cout<<add(9,8)<<endl;
    cout<<add(9.0,8.0)<<endl;
    cout<<add(9.0,8)<<endl;
    cout<<add('A','A'-'0')<<endl;
    cout<<add(long(8),9)<<endl;
    NumDelete<int,int,100>(5,2);// 这是显示实例化，前面都是隐式实例化。
    return 0;
}