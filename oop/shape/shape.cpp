// p7_9
#include<iostream>

using namespace std;

class Shape{
	public:
		virtual double area() const = 0;
		virtual void show() = 0;
};

class Point:public Shape{
	protected:
		int X,Y;
	public:
		Point(int X=0,int Y=0){
			this->X = X,this->Y = Y;
		}
		void show(){
			cout<<"("<<X<<","<<Y<<")"<<endl;
		}
		double area()const{
			return 0.0;
		}
};

const double PI=3.14159;

class Circle:public Point{
	protected:
		double radius;
	public:
		Circle(int X,int Y,double R):Point(X,Y){
			radius = R;
		}
		double area()const{
			return PI*radius*radius;
		}
		void show(){
			cout<<X<<","<<Y<<endl;
			cout<<radius<<endl;
		}
};

class Cylinder:public Circle{
	private:
		double height;
	public:
		Cylinder(int X,int Y,double R,double H):Circle(X,Y,R){
			height = H;
		}
		double area()const{
			return 2*Circle::area()+2*PI*radius*height;
		}
		void show(){
			Circle::show();
			cout<<height<<endl;
		}
};

int main(){
	Cylinder CY(100,200,10,50);
	Shape* P = &CY;
	P->show();
	cout<<P->area();
	Circle Cir(5,10,100);
	Shape& R = Cir;
	R.show();
	return 0;
}