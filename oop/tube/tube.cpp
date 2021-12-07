#include<iostream>

using namespace std;

class Point{
	private:
		int X,Y;
	public:
		Point(int X=0,int Y=0){
			this->X=X,this->Y=Y;
			cout<<"point constructing:"<<X<<","<<Y<<endl;
		}

		~Point(){
			cout<<"point desturcting:"<<X<<","<<Y<<endl;
		}
};

class Circle:protected Point{
	protected:
		double radius;
	public:
		Circle(double R=0,int X=0,int Y=0):Point(X,Y){
			radius=R;
			cout<<"circle constructing:"<<R<<endl;
		}

		~Circle(){
			cout<<"circle destructing:"<<radius<<endl;
		}
};

class Tube:protected Circle{
	private:
		double height;
		Circle InCircle;
	public:
		Tube(double H,double R2,double R1=0,int X=0,int Y=0):Circle(R1,X,Y),InCircle(R2,X,Y){// 这里的Circle是基类名，InCircle是成员对象名
			height = H;
			cout<<"tube constructing:"<<H<<endl;
		}

		~Tube(){
			cout<<"tube destructing:"<<height<<endl;
		}
};

int main(){
	Tube Tu(100,20,5);
	return 0;
}
