// p7_6
#include<iostream>

using namespace std;

class Point{
	private:
		int X,Y;
	public:
		Point(int X=0,int Y=0){
			this->X=X,this->Y=Y;
		}

		virtual double area(){
			return 0.0;
		}
};

const double PI = 3.14159;

class Circle:public Point{
	private:
		double radius;
	public:
		Circle(int X,int Y,double R):Point(X,Y){
			radius = R;
		}

		double area(){
			return PI*radius*radius;
		}
};

int main(){
	Point P1(10,10);
	cout<<P1.area()<<endl;
	Circle C1(10,10,20);
	cout<<C1.area()<<endl;
	Point* Pp = &C1;
	cout<<Pp->area();

	Point& Rp = C1;
	cout<<Rp.area()<<endl;
	return 0;
}