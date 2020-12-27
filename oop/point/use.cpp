// p6_1
#include "circle.h"

using namespace std;

int main(){
	Circle Cirl(10,100,200);
	Cirl.ShowCircle();
	cout<<"area is:"<<Cirl.area()<<endl;
	Cirl.move(10,20);
	Cirl.ShowXY();
	return 0;
}
