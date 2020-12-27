// p7_4
#include<iostream>

using namespace std;

class Complex{
    private:
        double real;
        double image;
    public:
        Complex(double real = 0.0,double image = 0.0){
            this->real = real,this->image = image;
        }

        void display(){
            cout<<"("<<real<<","<<image<<")";
        }
};

class PComplex{
    private:
        Complex* PC;
    public:
        PComplex(Complex* PC = NULL){
            this->PC = PC;
        }

        Complex* operator ->(){
            static Complex NullComplex(0,0);
            if (PC == NULL){
                return &NullComplex;
            }
            return PC;
        }
};

int main(){
    PComplex p1;
    p1->display();
    Complex C1(100,200);
    p1=&C1;
    p1->display();
    return 0;
}