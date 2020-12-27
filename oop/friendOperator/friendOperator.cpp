// p7_1
#include<iostream>

using namespace std;

class Complex {
    private:
        double real;
        double image;
    public:
        Complex(double real=0.0,double image=0.0){
            this->real = real;
            this->image = image;
        }

        void display(){
            cout<<"("<<real<<","<<image<<")"<<endl;
        }

        friend Complex operator + (Complex A,Complex B); // + 号
        friend Complex operator - (Complex A,Complex B); // - 号
        friend Complex operator - (Complex A);           // 取 负号
        friend Complex operator ++ (Complex A);          // 前置 ++ 
        friend Complex operator ++ (Complex A,int);      // 后置 ++
};

// Complex 是这个函数返回的类型，是个类。 operator - 构成函数名字。后面是参数列表
Complex operator + (Complex A,Complex B){
    return Complex(A.real+B.real,A.image+B.image);
}

Complex operator - (Complex A,Complex B){
    return Complex(A.real-B.real,A.image-B.image);
}

Complex operator - (Complex A){
    return Complex(-A.real,-A.image);
}

Complex operator ++ (Complex A){      // 如果没有&，不会对外面的A发生改变 
    return Complex(++A.real,A.image); // 前置 ++ 是先运算再传值，后置 ++ 先传再运算
}

Complex operator ++ (Complex A,int){
    return Complex(A.real++,A.image);
}

int main(){
    Complex A(100.0,200.0),B(-10.0,20.0),C;
    cout<<"A=",A.display();
    cout<<"B=",B.display();
    C = A+B;
    C.display();
    C = A-B;
    C.display();
    C = A++;
    C.display();
    C = ++A;
    C.display();
    C = A+8;
    C.display();
    return 0;
}