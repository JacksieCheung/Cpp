// 百元百鸡问题
// 先求 y z 通过 x 表示的表达式
// 再确定 x 的范围 => 通过 kx ky kz 大于 0 小于 100
#include<iostream>

int func(){
	int x=0,y=0,z=0;
	for (x=4;x<=12;x+=4){
		y=25-7*(x/4);
		z=75+3*(x/4);
		std::cout<<x<<" "<<y<<" "<<z<<std::endl;
	}
	return 0;
}

int main(){
	func();
	return 0;
}
