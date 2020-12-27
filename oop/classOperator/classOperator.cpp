// p7_2
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

        // 省略了左边的操作数，默认是类的对象，而且是取地址那种
        // 想要两个操作数能能互换，必须使用友元
        // 一般单目运算是类重载，双目运算友元重载
        Complex operator + (Complex B);
        Complex operator - (Complex B);
        Complex operator - ();
        Complex operator ++ ();
        Complex operator ++ (int);
};

Complex Complex::operator + (Complex B){
    return Complex(real + B.real,image+B.image);
}

Complex Complex::operator - (Complex B){
    return Complex(real - B.real,image-B.image);
}

Complex Complex::operator - (){
    return Complex(-real,-image);
}

Complex Complex::operator ++ (){
    return Complex(++real,image);
}

Complex Complex::operator ++ (int){
    return Complex(real++,image);
}

int main(){
    Complex A(100.0,200.0),B(-10.0,20.0),C;
    A.display();
    B.display();
    C = A+B;
    C.display();
    C = A-B;
    C.display();
    C = A++;
    C.display();
    C = ++A;
    C.display();
    C = A+5;
    C.display();
    return 0;
}