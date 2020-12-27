// p7_3
#include<iostream>

using namespace std;

class Complex{
    private:
        double real;
        double image;
    public:
        Complex(double real=0.0,double image=0.0){
            this->real = real;
            this->image = image;
        }

        void display(){
            cout<<"("<<real<<","<<image<<")";
        }

        Complex operator + (Complex B);
        Complex operator = (Complex B);
        Complex operator += (Complex B);
};

Complex Complex::operator + (Complex B){
    return Complex(real+B.real,image+B.image);
}

// = 重载常常用于深拷贝
Complex Complex::operator = (Complex B){
    real = B.real,image = B.image;
    return *this; // this 返回不需要构造函数，但会调用拷贝构造函数，注意深拷贝。
}

Complex Complex::operator += (Complex B){
    real = B.real+real;
    image = B.image+image;
    return *this;
}

int main(){
    Complex A(100.0,200.0),B(-10.0,20.0),C;
    C = A+B;
    C.display();
    C = A;
    C.display();
    C+=A;
    C.display();
    return 0;
}