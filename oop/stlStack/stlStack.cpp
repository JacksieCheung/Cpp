// p9_5
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

template<class T>
void output(T& stackdata){
    while(!stackdata.empty()){
        cout<<stackdata.top()<<" ";
        stackdata.pop();
    }
    cout<<endl;
}

int main(){
    stack<int> int_s;
    stack<int,vector<int>> vec_stack;
    for(int i=0;i<4;i++){
        int_s.push(i);
        vec_stack.push(i);
    }

    cout<<"Pop from int stack:"<<endl;
    output(int_s);
    cout<<"Pop from vec_stack:"<<endl;
    output(vec_stack);
    return 0;
}