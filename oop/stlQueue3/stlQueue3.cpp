// p9_4
#include<iostream>
#include<queue>
#include<list>

using namespace std;

template<class T>
void print(T &q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

int main(){
    queue<int,list<int>> list_q;// 容器适配器转换为顺序容器
    for(int i=1;i<=4;i++){
        list_q.push(i);
    }

    cout<<"The first element is : "<<list_q.front()<<endl;
    cout<<"The last element is : "<<list_q.back()<<endl;
    cout<<"The queue is: "<<endl;
    print(list_q);
    return 0;
}