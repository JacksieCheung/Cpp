#include<iostream>

using namespace std;

class Point {
	private:
		int X,Y;
	public:
		Point(int X=0,int Y=0){
			this->X=X,this->Y=Y;
		}
		void move(int OFFX,int OFFY){
			X+=OFFX,Y=OFFY;
		}
		void ShowXY(){
			cout<<"("<<X<<","<<Y<<")"<<endl;
		}
};
