// p6_3
#include<iostream>

using namespace std;

class Point{
	private:
		int X,Y;
	public:
		Point(int X=0,int Y=0){
			this->X = X,this->Y = Y;
			cout<<"Point constructing"<<endl;
		}
		~Point(){
			cout<<"Point destructing"<<endl;
		}
};

class Circle:protected Point{
	protected:
		double radius;
	public:
		Circle(double R=0,int X=0,int Y=0):Point(X,Y){
			radius=R;
			cout<<"circle constructing"<<endl;
		}
		~Circle(){
			cout<<"circle destructing"<<endl;
		}
};

class tube:protected Circle{
	private:
		double height;
		Circle InCircle;
	public:
		tube(double H,double R1,double R2=0,int X=0,int Y=0):InCircle(R2,X,Y),Circle(R1,X,Y){
			height = H;
			cout<<"tub constructing"<<endl;
		}
		~tube(){
			cout<<"tub destructing"<<endl;
		}
};

int main(){
	tube TU(100,20,5);
	return 0;
}
