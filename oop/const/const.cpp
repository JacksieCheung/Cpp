#include<iostream>

using namespace std;

class A {
	private:
		const int& r;
		const int a;
		static const int b;
	public:
		A(int i):a(i),r(a){ // 只能在函数后面的赋值列表赋值，别的地方只读
			cout<<"constructor"<<endl;
		}

		void display(){
			cout<<a<<","<<b<<","<<r<<endl;
		}
};

const int A::b = 3;

int main(){
	A a1(1);
	a1.display();
	A a2(2);
	a2.display();
	return 0;
}
