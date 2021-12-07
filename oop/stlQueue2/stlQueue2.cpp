// p9_3
#include<iostream>
#include<queue>
using namespace std;

template<class T>
void print(queue<T>&q){
    if(q.empty()) {
        cout<<"Queue is empty!"<<endl;
    } else {
        // 这是容器适配器，不是真的容器，不能使用迭代器
        int j = q.size();
        for (int i=0;i<j;i++){
            cout<<q.front()<<" ";
            q.pop();
        }
        cout<<endl;
    }
}

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<"The first element is: "<<q.front()<<endl;
    cout<<"The queue is: "<<endl;
    print(q);
    return 0;
}